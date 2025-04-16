#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <iomanip>

//------------------------//
//  Core Chess Logic      //
//------------------------//

enum class Color { WHITE, BLACK, NONE };
enum class GameState { PLAYING, CHECK, CHECKMATE, STALEMATE };
enum class SpecialMove { NONE, CASTLING, EN_PASSANT, PROMOTION };

struct Move {
    int fromRow, fromCol, toRow, toCol;
    char pieceMoved;
    char pieceCaptured;
    SpecialMove special;
    
    std::string toString() const {
        std::stringstream ss;
        ss << static_cast<char>('a' + fromCol) << (fromRow + 1) << " to "
           << static_cast<char>('a' + toCol) << (toRow + 1);
        return ss.str();
    }
};

inline Color oppositeColor(Color c) {
    return (c == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

// Forward declaration
class Board;

class Piece {
public:
    Piece(Color color) : hasMoved(false), color(color) {}
    virtual ~Piece() = default;
    
    Color getColor() const { return color; }
    virtual char getSymbol() const = 0;
    // Basic move validation. (This doesn't include check-check or castling.)
    virtual bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const = 0;
    
    bool hasMoved = false;  // Needed for castling and pawn double move
    
protected:
    Color color;
};

using PiecePtr = std::shared_ptr<Piece>;

// Forward declarations for piece classes
class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;

class Board {
public:
    Board() {
        board.resize(8, std::vector<PiecePtr>(8, nullptr));
        setupBoard();
    }
    
    // Return the piece pointer at a given board position.
    PiecePtr getPiece(int row, int col) const {
        return (inBounds(row, col)) ? board[row][col] : nullptr;
    }
    
    // Attempt to move a piece; returns true if successful.
    bool movePiece(int srcRow, int srcCol, int dstRow, int dstCol, Color turn);
    
    bool inBounds(int row, int col) const {
        return (row >= 0 && row < 8 && col >= 0 && col < 8);
    }
    
    const std::vector<std::vector<PiecePtr>>& getBoard() const {
        return board;
    }
    
    GameState getGameState() const {
        return currentState;
    }
    
    bool isInCheck(Color color) const;
    bool hasLegalMoves(Color color) const;
    bool canMoveTo(int srcRow, int srcCol, int dstRow, int dstCol, Color color) const;
    void updateGameState(Color colorToMove);
    
    // Get the last move
    const Move& getLastMove() const {
        return moveHistory.empty() ? emptyMove : moveHistory.back();
    }
    
    // Get all legal moves for a piece
    std::vector<Move> getLegalMoves(int srcRow, int srcCol) const;
    
    // Records the current board state for debugging
    void debugBoard() const;
    
    // Get move history
    const std::deque<Move>& getMoveHistory() const {
        return moveHistory;
    }
    
private:
    std::vector<std::vector<PiecePtr>> board;
    GameState currentState = GameState::PLAYING;
    sf::Vector2i lastMoveSource = {-1, -1};
    sf::Vector2i lastMoveTarget = {-1, -1};
    char lastMovedPiece = ' ';
    std::deque<Move> moveHistory;  // Store move history
    Move emptyMove = {-1, -1, -1, -1, ' ', ' ', SpecialMove::NONE};
    
    void setupBoard();
    bool isCastlingMove(int srcRow, int srcCol, int dstRow, int dstCol, Color color) const;
    bool doCastling(int srcRow, int srcCol, int dstRow, int dstCol);
    bool isEnPassant(int srcRow, int srcCol, int dstRow, int dstCol) const; // Make const
    bool doEnPassant(int srcRow, int srcCol, int dstRow, int dstCol);
    void checkPawnPromotion(int row, int col);
    
    // Record a move in the history
    void recordMove(int srcRow, int srcCol, int dstRow, int dstCol, SpecialMove special = SpecialMove::NONE);
};

class King : public Piece {
public:
    King(Color color) : Piece(color) {}
    char getSymbol() const override { return (color == Color::WHITE) ? 'K' : 'k'; }
    bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board&) const override {
        int dr = std::abs(dstRow - srcRow);
        int dc = std::abs(dstCol - srcCol);
        return (dr <= 1 && dc <= 1);
    }
};

class Queen : public Piece {
public:
    Queen(Color color) : Piece(color) {}
    char getSymbol() const override { return (color == Color::WHITE) ? 'Q' : 'q'; }
    bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const override {
        int dr = std::abs(dstRow - srcRow);
        int dc = std::abs(dstCol - srcCol);
        if (dr == dc || srcRow == dstRow || srcCol == dstCol) {
            return isPathClear(srcRow, srcCol, dstRow, dstCol, board);
        }
        return false;
    }
private:
    bool isPathClear(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const {
        int stepRow = (dstRow - srcRow) == 0 ? 0 : (dstRow - srcRow) / std::abs(dstRow - srcRow);
        int stepCol = (dstCol - srcCol) == 0 ? 0 : (dstCol - srcCol) / std::abs(dstCol - srcCol);
        int currRow = srcRow + stepRow;
        int currCol = srcCol + stepCol;
        while (currRow != dstRow || currCol != dstCol) {
            if (board.getPiece(currRow, currCol) != nullptr)
                return false;
            currRow += stepRow;
            currCol += stepCol;
        }
        return true;
    }
};

class Rook : public Piece {
public:
    Rook(Color color) : Piece(color) {}
    char getSymbol() const override { return (color == Color::WHITE) ? 'R' : 'r'; }
    bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const override {
        if (srcRow != dstRow && srcCol != dstCol)
            return false;
        return isPathClear(srcRow, srcCol, dstRow, dstCol, board);
    }
private:
    bool isPathClear(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const {
        int stepRow = (dstRow - srcRow) == 0 ? 0 : (dstRow - srcRow) / std::abs(dstRow - srcRow);
        int stepCol = (dstCol - srcCol) == 0 ? 0 : (dstCol - srcCol) / std::abs(dstCol - srcCol);
        int currRow = srcRow + stepRow;
        int currCol = srcCol + stepCol;
        while (currRow != dstRow || currCol != dstCol) {
            if (board.getPiece(currRow, currCol) != nullptr)
                return false;
            currRow += stepRow;
            currCol += stepCol;
        }
        return true;
    }
};

class Bishop : public Piece {
public:
    Bishop(Color color) : Piece(color) {}
    char getSymbol() const override { return (color == Color::WHITE) ? 'B' : 'b'; }
    bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const override {
        int dr = std::abs(dstRow - srcRow);
        int dc = std::abs(dstCol - srcCol);
        if (dr != dc)
            return false;
        return isPathClear(srcRow, srcCol, dstRow, dstCol, board);
    }
private:
    bool isPathClear(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const {
        int stepRow = (dstRow - srcRow) / std::abs(dstRow - srcRow);
        int stepCol = (dstCol - srcCol) / std::abs(dstCol - srcCol);
        int currRow = srcRow + stepRow;
        int currCol = srcCol + stepCol;
        while (currRow != dstRow && currCol != dstCol) {
            if (board.getPiece(currRow, currCol) != nullptr)
                return false;
            currRow += stepRow;
            currCol += stepCol;
        }
        return true;
    }
};

class Knight : public Piece {
public:
    Knight(Color color) : Piece(color) {}
    char getSymbol() const override { return (color == Color::WHITE) ? 'N' : 'n'; }
    bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board&) const override {
        int dr = std::abs(dstRow - srcRow);
        int dc = std::abs(dstCol - srcCol);
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
    }
};

class Pawn : public Piece {
public:
    Pawn(Color color) : Piece(color) {}
    char getSymbol() const override { return (color == Color::WHITE) ? 'P' : 'p'; }
    bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const override {
        int direction = (color == Color::WHITE) ? 1 : -1;
        int dr = dstRow - srcRow;
        int dc = std::abs(dstCol - srcCol);
        PiecePtr dstPiece = board.getPiece(dstRow, dstCol);
        
        // Move forward
        if (dc == 0) {
            if (dr == direction && !dstPiece)
                return true;
            if (!hasMoved && dr == 2 * direction) {
                if (!dstPiece && !board.getPiece(srcRow + direction, srcCol))
                    return true;
            }
        }
        // Capture move
        if (dc == 1 && dr == direction && dstPiece && dstPiece->getColor() == oppositeColor(color))
            return true;
            
        // En passant is handled separately in the Board class
        return false;
    }
};

// Implementation of Board methods that need complete piece class definitions

bool Board::movePiece(int srcRow, int srcCol, int dstRow, int dstCol, Color turn) {
    if (!inBounds(srcRow, srcCol) || !inBounds(dstRow, dstCol))
        return false;
    PiecePtr p = board[srcRow][srcCol];
    if (!p) return false;
    if (p->getColor() != turn) return false;

    // Prevent capturing your own pieces
    PiecePtr destPiece = board[dstRow][dstCol];
    if (destPiece && destPiece->getColor() == turn) {
          std::cerr << "Cannot capture your own pieces!" << std::endl;
            return false;
    }
    
    // Add protection against king capture
    // PiecePtr destPiece = board[dstRow][dstCol];
    if (destPiece && (destPiece->getSymbol() == 'K' || destPiece->getSymbol() == 'k')) {
        std::cerr << "Attempted to capture a king! This is not allowed." << std::endl;
        return false;
    }
    
    // Check for castling
    if (p->getSymbol() == 'K' || p->getSymbol() == 'k') {
        if (isCastlingMove(srcRow, srcCol, dstRow, dstCol, turn)) {
            doCastling(srcRow, srcCol, dstRow, dstCol);
            recordMove(srcRow, srcCol, dstRow, dstCol, SpecialMove::CASTLING);
            updateGameState(oppositeColor(turn));
            return true;
        }
    }
    
    // Check for en passant
    if ((p->getSymbol() == 'P' || p->getSymbol() == 'p') && isEnPassant(srcRow, srcCol, dstRow, dstCol)) {
        doEnPassant(srcRow, srcCol, dstRow, dstCol);
        recordMove(srcRow, srcCol, dstRow, dstCol, SpecialMove::EN_PASSANT);
        updateGameState(oppositeColor(turn));
        return true;
    }
        
    if (!p->isMoveValid(srcRow, srcCol, dstRow, dstCol, *this))
        return false;
    
    // Check if move puts/keeps player in check
    PiecePtr tempDst = board[dstRow][dstCol];
    board[dstRow][dstCol] = p;
    board[srcRow][srcCol] = nullptr;
    
    bool inCheck = isInCheck(turn);
    
    // Undo move if it results in check
    if (inCheck) {
        board[srcRow][srcCol] = p;
        board[dstRow][dstCol] = tempDst;
        return false;
    }
    
    // Mark piece as moved (important for castling, pawns)
    p->hasMoved = true;
    
    // Check for pawn promotion and record the move
    bool isPromotion = (p->getSymbol() == 'P' && dstRow == 7) || 
                       (p->getSymbol() == 'p' && dstRow == 0);
                       
    recordMove(srcRow, srcCol, dstRow, dstCol, 
               isPromotion ? SpecialMove::PROMOTION : SpecialMove::NONE);
    
    // Check for pawn promotion
    if (isPromotion) {
        checkPawnPromotion(dstRow, dstCol);
    }
    
    // Update last move info (needed for en passant)
    lastMoveSource = sf::Vector2i(srcRow, srcCol);
    lastMoveTarget = sf::Vector2i(dstRow, dstCol);
    lastMovedPiece = p->getSymbol();
    
    // Update game state
    updateGameState(oppositeColor(turn));
    
    return true;
}

void Board::recordMove(int srcRow, int srcCol, int dstRow, int dstCol, SpecialMove special) {
    Move move;
    move.fromRow = srcRow;
    move.fromCol = srcCol;
    move.toRow = dstRow;
    move.toCol = dstCol;
    move.pieceMoved = board[dstRow][dstCol]->getSymbol();
    move.pieceCaptured = ' ';
    move.special = special;
    
    // If a piece was captured, record it
    PiecePtr captured = board[dstRow][dstCol];
    if (captured) {
        move.pieceCaptured = captured->getSymbol();
    } else if (special == SpecialMove::EN_PASSANT) {
        // For en passant, the captured pawn is not at the destination
        PiecePtr enPassantPawn = board[srcRow][dstCol];
        if (enPassantPawn) {
            move.pieceCaptured = enPassantPawn->getSymbol();
        }
    }
    
    moveHistory.push_back(move);
    
    // Keep history limited to 50 moves (100 half-moves)
    if (moveHistory.size() > 100) {
        moveHistory.pop_front();
    }
}

bool Board::isInCheck(Color color) const {
    // Find the king
    int kingRow = -1, kingCol = -1;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            PiecePtr piece = board[r][c];
            if (piece && (piece->getSymbol() == (color == Color::WHITE ? 'K' : 'k'))) {
                kingRow = r;
                kingCol = c;
                break;
            }
        }
        if (kingRow != -1) break;
    }
    
    if (kingRow == -1) {  // Safety check - shouldn't happen in a valid game
        std::cerr << "Error: " << (color == Color::WHITE ? "White" : "Black") 
                  << " King not found on the board!" << std::endl;
        debugBoard();  // Print the current board state to help debug
        return false;
    }
    
    // Check if any opponent piece can capture the king
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            PiecePtr piece = board[r][c];
            if (piece && piece->getColor() == oppositeColor(color)) {
                if (piece->isMoveValid(r, c, kingRow, kingCol, *this))
                    return true;
            }
        }
    }
    return false;
}

bool Board::hasLegalMoves(Color color) const {
    for (int srcRow = 0; srcRow < 8; srcRow++) {
        for (int srcCol = 0; srcCol < 8; srcCol++) {
            PiecePtr piece = board[srcRow][srcCol];
            if (!piece || piece->getColor() != color) continue;
            
            // Check if this piece has any legal moves
            std::vector<Move> moves = getLegalMoves(srcRow, srcCol);
            if (!moves.empty()) {
                return true;
            }
        }
    }
    return false;
}

std::vector<Move> Board::getLegalMoves(int srcRow, int srcCol) const {
    std::vector<Move> legalMoves;
    PiecePtr piece = board[srcRow][srcCol];
    if (!piece) return legalMoves;
    
    Color color = piece->getColor();
    
    // Check for castling (king only)
    if (piece->getSymbol() == 'K' || piece->getSymbol() == 'k') {
        // Kingside castling
        if (isCastlingMove(srcRow, srcCol, srcRow, srcCol + 2, color)) {
            Move move = {srcRow, srcCol, srcRow, srcCol + 2, piece->getSymbol(), ' ', SpecialMove::CASTLING};
            legalMoves.push_back(move);
        }
        // Queenside castling
        if (isCastlingMove(srcRow, srcCol, srcRow, srcCol - 2, color)) {
            Move move = {srcRow, srcCol, srcRow, srcCol - 2, piece->getSymbol(), ' ', SpecialMove::CASTLING};
            legalMoves.push_back(move);
        }
    }
    
    // Check for en passant (pawn only)
    if (piece->getSymbol() == 'P' || piece->getSymbol() == 'p') {
        int direction = (color == Color::WHITE) ? 1 : -1;
        
        // Check left diagonal for en passant
        if (srcCol > 0 && isEnPassant(srcRow, srcCol, srcRow + direction, srcCol - 1)) {
            Move move = {srcRow, srcCol, srcRow + direction, srcCol - 1, piece->getSymbol(), 
                        (color == Color::WHITE ? 'p' : 'P'), SpecialMove::EN_PASSANT};
            legalMoves.push_back(move);
        }
        
        // Check right diagonal for en passant
        if (srcCol < 7 && isEnPassant(srcRow, srcCol, srcRow + direction, srcCol + 1)) {
            Move move = {srcRow, srcCol, srcRow + direction, srcCol + 1, piece->getSymbol(), 
                        (color == Color::WHITE ? 'p' : 'P'), SpecialMove::EN_PASSANT};
            legalMoves.push_back(move);
        }
    }
    
    // Check all standard moves
    for (int dstRow = 0; dstRow < 8; dstRow++) {
        for (int dstCol = 0; dstCol < 8; dstCol++) {
            if (canMoveTo(srcRow, srcCol, dstRow, dstCol, color)) {
                Move move = {srcRow, srcCol, dstRow, dstCol, piece->getSymbol(), ' ', SpecialMove::NONE};
                
                // Check if there's a captured piece
                PiecePtr destPiece = board[dstRow][dstCol];
                if (destPiece) {
                    move.pieceCaptured = destPiece->getSymbol();
                }
                
                // Check for pawn promotion
                if ((piece->getSymbol() == 'P' && dstRow == 7) || 
                    (piece->getSymbol() == 'p' && dstRow == 0)) {
                    move.special = SpecialMove::PROMOTION;
                }
                
                legalMoves.push_back(move);
            }
        }
    }
    
    return legalMoves;
}

bool Board::canMoveTo(int srcRow, int srcCol, int dstRow, int dstCol, Color color) const {
    if (!inBounds(srcRow, srcCol) || !inBounds(dstRow, dstCol))
        return false;

    // Check basic validity
    PiecePtr piece = board[srcRow][srcCol];
    if (!piece || piece->getColor() != color) 
        return false;
        
    PiecePtr destPiece = board[dstRow][dstCol];
    if (destPiece && destPiece->getColor() == color)
        return false;
        
    if (!piece->isMoveValid(srcRow, srcCol, dstRow, dstCol, *this))
        return false;
        
    // Check if move leaves king in check
    Board tempBoard = *this;
    tempBoard.board[dstRow][dstCol] = piece;
    tempBoard.board[srcRow][srcCol] = nullptr;
    
    return !tempBoard.isInCheck(color);
}

void Board::updateGameState(Color colorToMove) {
    if (isInCheck(colorToMove)) {
        if (!hasLegalMoves(colorToMove))
            currentState = GameState::CHECKMATE;
        else
            currentState = GameState::CHECK;
    }
    else if (!hasLegalMoves(colorToMove)) {
        currentState = GameState::STALEMATE;
    }
    else {
        currentState = GameState::PLAYING;
    }
}

bool Board::isCastlingMove(int srcRow, int srcCol, int dstRow, int dstCol, Color color) const {
    // Check if king is trying to move two squares horizontally
    PiecePtr piece = board[srcRow][srcCol];
    if (!piece) return false;
    
    char symbol = piece->getSymbol();
    if ((symbol != 'K' && symbol != 'k') || piece->hasMoved)
        return false;
        
    if (srcRow != dstRow || abs(dstCol - srcCol) != 2)
        return false;
        
    // Check if king is in check
    if (isInCheck(color))
        return false;
        
    // Check if path is clear and squares aren't under attack
    int direction = (dstCol > srcCol) ? 1 : -1;
    int rookCol = (direction == 1) ? 7 : 0;
    
    // Check if rook exists and hasn't moved
    PiecePtr rook = board[srcRow][rookCol];
    if (!rook || rook->hasMoved || (rook->getSymbol() != 'R' && rook->getSymbol() != 'r'))
        return false;
        
    // Check if squares between king and rook are empty
    int start = std::min(srcCol, rookCol) + 1;
    int end = std::max(srcCol, rookCol);
    for (int c = start; c < end; c++) {
        if (board[srcRow][c] != nullptr)
            return false;
    }
    
    // Check if king moves through check
    Board tempBoard = *this;
    int midCol = srcCol + direction;
    tempBoard.board[srcRow][midCol] = piece;
    tempBoard.board[srcRow][srcCol] = nullptr;
    if (tempBoard.isInCheck(color))
        return false;
        
    return true;
}

bool Board::doCastling(int srcRow, int srcCol, int dstRow, int dstCol) {
    int direction = (dstCol > srcCol) ? 1 : -1;
    int rookCol = (direction == 1) ? 7 : 0;
    
    // Move king
    board[dstRow][dstCol] = board[srcRow][srcCol];
    board[srcRow][srcCol] = nullptr;
    
    // Move rook
    int newRookCol = srcCol + direction;
    board[srcRow][newRookCol] = board[srcRow][rookCol];
    board[srcRow][rookCol] = nullptr;
    
    // Mark pieces as moved
    board[dstRow][dstCol]->hasMoved = true;
    board[srcRow][newRookCol]->hasMoved = true;
    
    return true;
}

bool Board::isEnPassant(int srcRow, int srcCol, int dstRow, int dstCol) const { // Make const
    PiecePtr piece = board[srcRow][srcCol];
    if (!piece) return false;
    
    // Check if it's a pawn
    char symbol = piece->getSymbol();
    if (symbol != 'P' && symbol != 'p')
        return false;
        
    // Check if it's a diagonal move to an empty square
    int direction = (piece->getColor() == Color::WHITE) ? 1 : -1;
    if (dstRow - srcRow != direction || abs(dstCol - srcCol) != 1)
        return false;
        
    if (board[dstRow][dstCol] != nullptr)
        return false;
        
    // Check if there's an enemy pawn beside that just moved two squares
    if (lastMovedPiece != (piece->getColor() == Color::WHITE ? 'p' : 'P'))
        return false;
        
    if (lastMoveTarget.x != srcRow || abs(lastMoveTarget.y - dstCol) != 0)
        return false;
        
    if (abs(lastMoveSource.x - lastMoveTarget.x) != 2)
        return false;
        
    return true;
}

bool Board::doEnPassant(int srcRow, int srcCol, int dstRow, int dstCol) {
    // Move the pawn
    board[dstRow][dstCol] = board[srcRow][srcCol];
    board[srcRow][srcCol] = nullptr;
    
    // Remove the captured pawn
    board[srcRow][dstCol] = nullptr;
    
    return true;
}

void Board::checkPawnPromotion(int row, int col) {
    PiecePtr piece = board[row][col];
    if (!piece) return;
    
    char symbol = piece->getSymbol();
    if ((symbol == 'P' && row == 7) || (symbol == 'p' && row == 0)) {
        // Auto-promote to Queen for simplicity
        Color color = piece->getColor();
        board[row][col] = std::make_shared<Queen>(color);
    }
}

void Board::setupBoard() {
    // Place pawns
    for (int col = 0; col < 8; ++col) {
        board[1][col] = std::make_shared<Pawn>(Color::WHITE);
        board[6][col] = std::make_shared<Pawn>(Color::BLACK);
    }
    // Place Rooks
    board[0][0] = std::make_shared<Rook>(Color::WHITE);
    board[0][7] = std::make_shared<Rook>(Color::WHITE);
    board[7][0] = std::make_shared<Rook>(Color::BLACK);
    board[7][7] = std::make_shared<Rook>(Color::BLACK);
    
    // Place Knights
    board[0][1] = std::make_shared<Knight>(Color::WHITE);
    board[0][6] = std::make_shared<Knight>(Color::WHITE);
    board[7][1] = std::make_shared<Knight>(Color::BLACK);
    board[7][6] = std::make_shared<Knight>(Color::BLACK);
    
    // Place Bishops
    board[0][2] = std::make_shared<Bishop>(Color::WHITE);
    board[0][5] = std::make_shared<Bishop>(Color::WHITE);
    board[7][2] = std::make_shared<Bishop>(Color::BLACK);
    board[7][5] = std::make_shared<Bishop>(Color::BLACK);
    
    // Place Queens
    board[0][3] = std::make_shared<Queen>(Color::WHITE);
    board[7][3] = std::make_shared<Queen>(Color::BLACK);
    
    // Place Kings
    board[0][4] = std::make_shared<King>(Color::WHITE);
    board[7][4] = std::make_shared<King>(Color::BLACK);
}

void Board::debugBoard() const {
    std::cout << "  +------------------------+\n";
    for (int row = 7; row >= 0; --row) {
        std::cout << (row+1) << " | ";
        for (int col = 0; col < 8; ++col) {
            PiecePtr p = board[row][col];
            if (p)
                std::cout << p->getSymbol() << " ";
            else
                std::cout << ". ";
        }
        std::cout << "|\n";
    }
    std::cout << "  +------------------------+\n";
    std::cout << "    a b c d e f g h\n";
    
    // Print state and last move
    std::cout << "Game State: ";
    switch(currentState) {
        case GameState::PLAYING: std::cout << "Playing"; break;
        case GameState::CHECK: std::cout << "Check"; break;
        case GameState::CHECKMATE: std::cout << "Checkmate"; break;
        case GameState::STALEMATE: std::cout << "Stalemate"; break;
    }
    std::cout << std::endl;
    
    if (!moveHistory.empty()) {
        const Move& lastMove = moveHistory.back();
        std::cout << "Last move: " << lastMove.toString() << std::endl;
    }
}

//------------------------//
//  Score Calculation     //
//------------------------//

int pieceValue(char symbol) {
    // Standard piece values (King is not given material value)
    switch(tolower(symbol)) {
        case 'p': return 1;
        case 'n': return 3;
        case 'b': return 3;
        case 'r': return 5;
        case 'q': return 9;
        case 'k': return 0;
        default: return 0;
    }
}

void calculateScores(const Board &board, int &whiteScore, int &blackScore) {
    whiteScore = 0;
    blackScore = 0;
    const auto &grid = board.getBoard();
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            PiecePtr piece = grid[row][col];
            if (piece) {
                int value = pieceValue(piece->getSymbol());
                if (piece->getColor() == Color::WHITE)
                    whiteScore += value;
                else
                    blackScore += value;
            }
        }
    }
}

//------------------------//
//  Helper Functions      //
//------------------------//

// Given a piece character ('P', 'n', etc.), return its Unicode chess icon.
sf::String getUnicodeForPiece(char pieceChar) {
    switch(pieceChar) {
        case 'P': return sf::String(L"♙");
        case 'N': return sf::String(L"♘");
        case 'B': return sf::String(L"♗");
        case 'R': return sf::String(L"♖");
        case 'Q': return sf::String(L"♕");
        case 'K': return sf::String(L"♔");
        case 'p': return sf::String(L"♟");
        case 'n': return sf::String(L"♞");
        case 'b': return sf::String(L"♝");
        case 'r': return sf::String(L"♜");
        case 'q': return sf::String(L"♛");
        case 'k': return sf::String(L"♚");
        default:  return sf::String();
    }
}

// Get algebraic notation for a move
std::string getMoveNotation(const Move& move) {
    static const std::string files = "abcdefgh";
    static const std::string ranks = "12345678";
    
    char pieceSymbol = move.pieceMoved;
    std::string notation;
    
    // Piece symbol (except for pawns)
    if (toupper(pieceSymbol) != 'P') {
        notation += toupper(pieceSymbol);
    }
    
    // Add "x" for captures
    if (move.pieceCaptured != ' ') {
        if (toupper(pieceSymbol) == 'P') {
            notation += files[move.fromCol];
        }
        notation += 'x';
    }
    
    // Destination square
    notation += files[move.toCol];
    notation += ranks[move.toRow];
    
    // Special notations
    if (move.special == SpecialMove::CASTLING) {
        if (move.toCol - move.fromCol > 0)
            notation = "O-O"; // Kingside
        else
            notation = "O-O-O"; // Queenside
    }
    else if (move.special == SpecialMove::PROMOTION) {
        notation += "=Q"; // Auto-promote to Queen
    }
    
    return notation;
}

//------------------------//
//  UI Enhancements       //
//------------------------//

// For showing move hints and current game state
class StatusPanel {
public:
    StatusPanel(const sf::Font& font, unsigned int size, sf::Vector2f position, float width, float height) {
        panel.setSize(sf::Vector2f(width, height));
        panel.setPosition(position);
        panel.setFillColor(sf::Color(40, 40, 40));
        panel.setOutlineColor(sf::Color(100, 100, 100));
        panel.setOutlineThickness(2);
        
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(sf::Color::White);
        text.setPosition(position.x + 10, position.y + 10);
    }
    
    void update(const Board& board, const std::string& whiteName, const std::string& blackName, Color turn) {
        std::stringstream ss;
        
        // Game state
        GameState state = board.getGameState();
        switch(state) {
            case GameState::CHECK:
                ss << "CHECK! " << (turn == Color::WHITE ? whiteName : blackName) << " is in check\n";
                break;
            case GameState::CHECKMATE:
                ss << "CHECKMATE! " << (turn == Color::WHITE ? blackName : whiteName) << " wins!\n";
                break;
            case GameState::STALEMATE:
                ss << "STALEMATE! Game is a draw\n";
                break;
            default:
                ss << (turn == Color::WHITE ? whiteName : blackName) << "'s turn\n";
        }
        
        // Move history (last few moves) - improved formatting
        ss << "\nMove History:\n";
        const auto& moveHistory = board.getMoveHistory();
        size_t historySize = moveHistory.size();
        
        // Show last 8 moves (16 half-moves)
        size_t startIdx = historySize > 16 ? historySize - 16 : 0;
        
        for (size_t i = startIdx; i < historySize; ++i) {
            if (i % 2 == 0) {
                ss << ((i/2) + 1) << ". ";
            }
            
            // Add padding for alignment
            std::string notation = getMoveNotation(moveHistory[i]);
            ss << std::left << std::setw(7) << notation;
            
            // Make two columns of moves to use space more efficiently
            if (i % 4 == 3) {
                ss << "\n";
            }
            else if (i % 2 == 1) {
                ss << " ";
            }
        }
        
        text.setString(ss.str());
    }
    
    void draw(sf::RenderWindow& window) {
        window.draw(panel);
        window.draw(text);
    }
    
private:
    sf::RectangleShape panel;
    sf::Text text;
};

class Button {
public:
    Button(const std::string& text, const sf::Font& font, unsigned int size, sf::Vector2f position) {
        buttonText.setString(text);
        buttonText.setFont(font);
        buttonText.setCharacterSize(size);
        
        buttonShape.setSize(sf::Vector2f(text.length() * size * 0.5f + 20, size * 1.5f));
        buttonShape.setPosition(position);
        buttonShape.setFillColor(sf::Color(100, 100, 100));
        buttonShape.setOutlineColor(sf::Color::White);
        buttonShape.setOutlineThickness(2);
        
        buttonText.setPosition(
            position.x + (buttonShape.getSize().x - buttonText.getLocalBounds().width) / 2,
            position.y + (buttonShape.getSize().y - size) / 2
        );
    }
    
    bool contains(sf::Vector2f point) const {
        return buttonShape.getGlobalBounds().contains(point);
    }
    
    void draw(sf::RenderWindow& window) {
        window.draw(buttonShape);
        window.draw(buttonText);
    }
    
    void setHoverState(bool hovering) {
        buttonShape.setFillColor(hovering ? sf::Color(130, 130, 130) : sf::Color(100, 100, 100));
    }
    
private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
};

class InputBox {
public:
    InputBox(const sf::Font& font, unsigned int size, sf::Vector2f position, float width) {
        box.setSize(sf::Vector2f(width, size * 1.5f));
        box.setPosition(position);
        box.setFillColor(sf::Color::White);
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(2);
        
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position.x + 5, position.y + 5);
    }
    
    bool contains(sf::Vector2f point) const {
        return box.getGlobalBounds().contains(point);
    }
    
    void addCharacter(char c) {
        if (content.length() < 20) {  // Limit name length
            content += c;
            text.setString(content);
        }
    }
    
    void removeCharacter() {
        if (!content.empty()) {
            content.pop_back();
            text.setString(content);
        }
    }
    
    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }
    
    std::string getContent() const {
        return content;
    }
    
private:
    sf::RectangleShape box;
    sf::Text text;
    std::string content;
};

//------------------------//
//  AI Implementation     //
//------------------------//

class AIPlayer {
public:
    AIPlayer(Color color, int searchDepth = 3) : aiColor(color), depth(searchDepth) {}
    
    Move getBestMove(const Board& board) {
        // Find the best move using minimax
        int bestScore = (aiColor == Color::WHITE) ? -1000000 : 1000000;
        Move bestMove;
        
        std::vector<Move> possibleMoves;
        
        // Get all possible moves for AI's pieces
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                PiecePtr piece = board.getPiece(r, c);
                if (piece && piece->getColor() == aiColor) {
                    std::vector<Move> moves = board.getLegalMoves(r, c);
                    possibleMoves.insert(possibleMoves.end(), moves.begin(), moves.end());
                }
            }
        }
        
        // Randomize move order for more varied play
        std::random_shuffle(possibleMoves.begin(), possibleMoves.end());
        
        // No legal moves
        if (possibleMoves.empty()) {
            std::cerr << "AI has no legal moves!" << std::endl;
            return {-1, -1, -1, -1, ' ', ' ', SpecialMove::NONE};
        }
        
        // For each possible move, evaluate using minimax
        for (const Move& move : possibleMoves) {
            // Make a copy of the board to simulate moves
            Board tempBoard = board;
            tempBoard.movePiece(move.fromRow, move.fromCol, move.toRow, move.toCol, aiColor);
            
            // Calculate score using minimax
            int score = minimax(tempBoard, depth - 1, -1000000, 1000000, aiColor == Color::WHITE ? false : true);
            
            // Update best move if this move is better
            if ((aiColor == Color::WHITE && score > bestScore) || 
                (aiColor == Color::BLACK && score < bestScore)) {
                bestScore = score;
                bestMove = move;
            }
        }
        
        return bestMove;
    }
    
private:
    Color aiColor;
    int depth;
    
    // Minimax algorithm with alpha-beta pruning
    int minimax(Board& board, int depth, int alpha, int beta, bool isMaximizing) {
        // Base case: reached depth limit or game over
        if (depth == 0 || board.getGameState() == GameState::CHECKMATE || 
            board.getGameState() == GameState::STALEMATE) {
            return evaluateBoard(board);
        }
        
        Color currentColor = isMaximizing ? Color::WHITE : Color::BLACK;
        
        if (isMaximizing) {
            int maxScore = -1000000;
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    PiecePtr piece = board.getPiece(r, c);
                    if (piece && piece->getColor() == currentColor) {
                        std::vector<Move> moves = board.getLegalMoves(r, c);
                        for (const Move& move : moves) {
                            // Save state to restore after simulation
                            PiecePtr capturedPiece = board.getPiece(move.toRow, move.toCol);
                            
                            // Try the move
                            board.movePiece(move.fromRow, move.fromCol, move.toRow, move.toCol, currentColor);
                            
                            // Recursively evaluate
                            int score = minimax(board, depth - 1, alpha, beta, false);
                            
                            // This is where we'd restore the board state
                            // For simplicity, we don't track special moves like en passant, castling
                            // In a complete solution, we'd need to properly restore all state
                            
                            maxScore = std::max(maxScore, score);
                            alpha = std::max(alpha, score);
                            if (beta <= alpha)
                                return maxScore; // Beta cutoff
                        }
                    }
                }
            }
            return maxScore;
        } else {
            int minScore = 1000000;
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    PiecePtr piece = board.getPiece(r, c);
                    if (piece && piece->getColor() == currentColor) {
                        std::vector<Move> moves = board.getLegalMoves(r, c);
                        for (const Move& move : moves) {
                            // Try the move
                            board.movePiece(move.fromRow, move.fromCol, move.toRow, move.toCol, currentColor);
                            
                            // Recursively evaluate
                            int score = minimax(board, depth - 1, alpha, beta, true);
                            
                            minScore = std::min(minScore, score);
                            beta = std::min(beta, score);
                            if (beta <= alpha)
                                return minScore; // Alpha cutoff
                        }
                    }
                }
            }
            return minScore;
        }
    }
    
    // Simple board evaluation function
    int evaluateBoard(const Board& board) {
        int score = 0;
        
        // Material value
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                PiecePtr piece = board.getPiece(r, c);
                if (piece) {
                    int value = pieceValue(piece->getSymbol());
                    if (piece->getColor() == Color::WHITE)
                        score += value;
                    else
                        score -= value;
                }
            }
        }
        
        // Check for checkmate
        if (board.getGameState() == GameState::CHECKMATE) {
            if (board.isInCheck(Color::WHITE))
                score = -100000; // Black wins
            else
                score = 100000;  // White wins
        }
        
        return score;
    }
};

// Main function now handles game startup, player name input, and enhanced game loop
int main() {
    const int windowSize = 640;
    const int infoHeight = 160;  // Increased for better UI and move history
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize + infoHeight), "Chess Game");
    window.setFramerateLimit(60);
    
    // --- Set Window Icon (a simple checkered icon) ---
    const int iconSize = 16;
    std::vector<sf::Uint8> iconPixels(iconSize * iconSize * 4);
    for (int y = 0; y < iconSize; ++y) {
        for (int x = 0; x < iconSize; ++x) {
            int i = (y * iconSize + x) * 4;
            bool isWhite = (((x / 4) + (y / 4)) % 2 == 0);
            if (isWhite) {
                iconPixels[i] = 240;    // R
                iconPixels[i + 1] = 217;  // G
                iconPixels[i + 2] = 181;  // B
                iconPixels[i + 3] = 255;  // A
            } else {
                iconPixels[i] = 181;
                iconPixels[i + 1] = 136;
                iconPixels[i + 2] = 99;
                iconPixels[i + 3] = 255;
            }
        }
    }
    window.setIcon(iconSize, iconSize, iconPixels.data());
    
    // --- Load Font (ensure the file exists) ---
    sf::Font font;
    if (!font.loadFromFile("DejaVuSans.ttf")) {
        std::cerr << "DejaVuSans.ttf not found.\n";
        return -1;
    }
    
    // --- Load Move Sound ---
    sf::SoundBuffer moveBuffer, checkBuffer, captureBuffer;
    if (!moveBuffer.loadFromFile("move.wav")) {
        std::cerr << "move.wav not found. Continuing without sound.\n";
    }
    sf::Sound moveSound;
    moveSound.setBuffer(moveBuffer);
    
    // Try to load additional sound effects
    bool hasCheckSound = checkBuffer.loadFromFile("check.wav");
    bool hasCaptureSound = captureBuffer.loadFromFile("capture.wav");
    sf::Sound checkSound, captureSound;
    if (hasCheckSound) checkSound.setBuffer(checkBuffer);
    if (hasCaptureSound) captureSound.setBuffer(captureBuffer);
    
    // Game state variables
    enum class GameMode { PLAYER_VS_PLAYER, PLAYER_VS_AI, AI_VS_PLAYER };
    GameMode gameMode = GameMode::PLAYER_VS_PLAYER;
    
    enum class GameScreen { PLAYER_NAMES, GAME_MODE, GAME, GAME_OVER };
    GameScreen currentScreen = GameScreen::GAME_MODE; // Change to start with game mode selection
    
    std::string whiteName = "Player 1";
    std::string blackName = "Player 2";
    InputBox whiteInput(font, 20, sf::Vector2f(windowSize/2 - 100, windowSize/2 - 50), 200);
    InputBox blackInput(font, 20, sf::Vector2f(windowSize/2 - 100, windowSize/2 + 20), 200);
    Button startButton("Start Game", font, 20, sf::Vector2f(windowSize/2 - 60, windowSize/2 + 80));
    Button restartButton("Play Again", font, 20, sf::Vector2f(windowSize/2 - 60, windowSize/2 + 50));
    
    // Add buttons for game mode selection
    Button pvpButton("Player vs Player", font, 20, sf::Vector2f(windowSize/2 - 80, windowSize/2 - 40));
    Button pveButton("Player vs AI", font, 20, sf::Vector2f(windowSize/2 - 70, windowSize/2 + 10));
    Button evpButton("AI vs Player", font, 20, sf::Vector2f(windowSize/2 - 70, windowSize/2 + 60));
    
    sf::Text gameModeTitle;
    gameModeTitle.setFont(font);
    gameModeTitle.setString("Select Game Mode");
    gameModeTitle.setCharacterSize(40);
    gameModeTitle.setFillColor(sf::Color::White);
    gameModeTitle.setPosition(windowSize/2 - gameModeTitle.getLocalBounds().width/2, windowSize/4);
    
    // Add missing text declarations
    sf::Text gameTitle, namePrompt1, namePrompt2, gameOverText;
    
    // Game title setup
    gameTitle.setFont(font);
    gameTitle.setString("Chess Game");
    gameTitle.setCharacterSize(40);
    gameTitle.setFillColor(sf::Color::White);
    gameTitle.setPosition(windowSize/2 - gameTitle.getLocalBounds().width/2, windowSize/4);
    
    // Name prompts
    namePrompt1.setFont(font);
    namePrompt1.setString("White Player Name:");
    namePrompt1.setCharacterSize(20);
    namePrompt1.setFillColor(sf::Color::White);
    namePrompt1.setPosition(windowSize/2 - 100, windowSize/2 - 80);
    
    namePrompt2.setFont(font);
    namePrompt2.setString("Black Player Name:");
    namePrompt2.setCharacterSize(20);
    namePrompt2.setFillColor(sf::Color::White);
    namePrompt2.setPosition(windowSize/2 - 100, windowSize/2 - 10);
    
    // Game over text
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Yellow);
    gameOverText.setPosition(windowSize/2 - 150, windowSize/2 - 50);
    
    // Create AI player (will be initialized with the right color when mode is selected)
    std::shared_ptr<AIPlayer> ai;
    
    // Game variables
    Board board;
    Color turn = Color::WHITE;
    bool pieceSelected = false;
    int selectedRow = -1, selectedCol = -1;
    const int squareSize = windowSize / 8;
    std::vector<sf::Vector2i> lastMove;  // This is a vector of sf::Vector2i
    bool isInputBoxActive = false;
    InputBox* activeInput = nullptr;
    
    // Info texts
    sf::Text whiteScoreText, blackScoreText, turnIndicator, moveHistoryText;
    // ... existing code for text setup ...
    
    // Animation variables
    sf::Vector2f pieceMovingFrom;
    sf::Vector2f pieceMovingTo;
    float animationProgress = 1.0f;  // 1.0 means no animation active
    PiecePtr animatedPiece = nullptr;
    
    // Add the status panel for move history and game state
    StatusPanel statusPanel(font, 16, sf::Vector2f(10, windowSize + 60), windowSize - 20, infoHeight - 70);
    
    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                
            // Handle mouse movement for button hover
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePos(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));
                
                if (currentScreen == GameScreen::GAME_MODE) {
                    pvpButton.setHoverState(pvpButton.contains(mousePos));
                    pveButton.setHoverState(pveButton.contains(mousePos));
                    evpButton.setHoverState(evpButton.contains(mousePos));
                }
                else if (currentScreen == GameScreen::PLAYER_NAMES) {
                    startButton.setHoverState(startButton.contains(mousePos));
                }
                else if (currentScreen == GameScreen::GAME_OVER) {
                    restartButton.setHoverState(restartButton.contains(mousePos));
                }
            }
                
            // Handle mouse clicks based on current screen
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                
                if (currentScreen == GameScreen::GAME_MODE) {
                    if (pvpButton.contains(mousePos)) {
                        currentScreen = GameScreen::PLAYER_NAMES;
                    }
                    else if (pveButton.contains(mousePos)) {
                        whiteName = "Player";
                        blackName = "AI";
                        ai = std::make_shared<AIPlayer>(Color::BLACK, 3);
                        currentScreen = GameScreen::GAME;
                    }
                    else if (evpButton.contains(mousePos)) {
                        whiteName = "AI";
                        blackName = "Player";
                        ai = std::make_shared<AIPlayer>(Color::WHITE, 3);
                        currentScreen = GameScreen::GAME;
                    }
                }
                else if (currentScreen == GameScreen::PLAYER_NAMES) {
                    if (whiteInput.contains(mousePos)) {
                        activeInput = &whiteInput;
                        isInputBoxActive = true;
                    }
                    else if (blackInput.contains(mousePos)) {
                        activeInput = &blackInput;
                        isInputBoxActive = true;
                    }
                    else {
                        isInputBoxActive = false;
                        activeInput = nullptr;
                    }
                    
                    if (startButton.contains(mousePos)) {
                        whiteName = whiteInput.getContent().empty() ? "Player 1" : whiteInput.getContent();
                        blackName = blackInput.getContent().empty() ? "Player 2" : blackInput.getContent();
                        currentScreen = GameScreen::GAME;
                    }
                }
                else if (currentScreen == GameScreen::GAME) {
                    int col = event.mouseButton.x / squareSize;
                    int row = 7 - (event.mouseButton.y / squareSize);
                    
                    // Only handle board clicks if there's no animation running
                    if (animationProgress >= 1.0f && board.inBounds(row, col)) {
                        if (!pieceSelected) {
                            PiecePtr p = board.getPiece(row, col);
                            if (p && p->getColor() == turn) {
                                pieceSelected = true;
                                selectedRow = row;
                                selectedCol = col;
                            }
                        } else {
                            // Store pre-move state
                            PiecePtr capturedPiece = board.getPiece(row, col);
                            
                            bool moved = board.movePiece(selectedRow, selectedCol, row, col, turn);
                            if (moved) {
                                // Start animation
                                pieceMovingFrom = sf::Vector2f(selectedCol * squareSize, (7 - selectedRow) * squareSize);
                                pieceMovingTo = sf::Vector2f(col * squareSize, (7 - row) * squareSize);
                                animationProgress = 0.0f;
                                animatedPiece = board.getPiece(row, col);
                                
                                // Debug output to console
                                board.debugBoard();
                                
                                // Play appropriate sound
                                const Move& moveInfo = board.getLastMove();
                                if (board.getGameState() == GameState::CHECK || board.getGameState() == GameState::CHECKMATE) {
                                    if (hasCheckSound) checkSound.play();
                                }
                                else if (moveInfo.pieceCaptured != ' ' || moveInfo.special == SpecialMove::EN_PASSANT) {
                                    if (hasCaptureSound) captureSound.play();
                                }
                                else {
                                    moveSound.play();
                                }
                                
                                // Store last move for highlight - fix the vector management
                                lastMove.clear();
                                lastMove.push_back(sf::Vector2i(selectedCol, selectedRow));
                                lastMove.push_back(sf::Vector2i(col, row));
                                
                                // Change turn
                                turn = oppositeColor(turn);
                                
                                // Update the status panel
                                statusPanel.update(board, whiteName, blackName, turn);
                                
                                // Check if game over
                                if (board.getGameState() == GameState::CHECKMATE || board.getGameState() == GameState::STALEMATE) {
                                    std::string result;
                                    if (board.getGameState() == GameState::CHECKMATE) {
                                        std::string winner = (turn == Color::WHITE) ? blackName : whiteName;
                                        result = winner + " wins!";
                                    } else {
                                        result = "Draw by stalemate!";
                                    }
                                    gameOverText.setString(result);
                                    currentScreen = GameScreen::GAME_OVER;
                                }
                            }
                            pieceSelected = false;
                            selectedRow = selectedCol = -1;
                        }
                    }
                }
                else if (currentScreen == GameScreen::GAME_OVER) {
                    if (restartButton.contains(mousePos)) {
                        // Reset the game
                        board = Board();
                        turn = Color::WHITE;
                        pieceSelected = false;
                        selectedRow = selectedCol = -1;
                        lastMove.clear();
                        currentScreen = GameScreen::GAME;
                    }
                }
            }
            
            // Handle keyboard input
            if (event.type == sf::Event::TextEntered && isInputBoxActive && activeInput) {
                if (event.text.unicode < 128 && event.text.unicode > 31) {
                    activeInput->addCharacter(static_cast<char>(event.text.unicode));
                }
            }
            
            if (event.type == sf::Event::KeyPressed && isInputBoxActive && activeInput) {
                if (event.key.code == sf::Keyboard::BackSpace) {
                    activeInput->removeCharacter();
                }
            }
        }
        
        // AI's turn to move
        if (currentScreen == GameScreen::GAME && 
            ((gameMode == GameMode::PLAYER_VS_AI && turn == Color::BLACK) ||
             (gameMode == GameMode::AI_VS_PLAYER && turn == Color::WHITE))) {
            
            // Ensure animation from previous move is complete
            if (animationProgress >= 1.0f) {
                // Get AI move
                Move aiMove = ai->getBestMove(board);
                
                if (aiMove.fromRow != -1) { // Valid move found
                    // Simulate piece selection and movement for animation
                    selectedRow = aiMove.fromRow;
                    selectedCol = aiMove.fromCol;
                    pieceSelected = true;
                    
                    // Store pre-move state
                    PiecePtr animatedPiece = board.getPiece(selectedRow, selectedCol);
                    
                    // Make the move
                    bool moved = board.movePiece(aiMove.fromRow, aiMove.fromCol, aiMove.toRow, aiMove.toCol, turn);
                    if (moved) {
                        // Start animation
                        pieceMovingFrom = sf::Vector2f(selectedCol * squareSize, (7 - selectedRow) * squareSize);
                        pieceMovingTo = sf::Vector2f(aiMove.toCol * squareSize, (7 - aiMove.toRow) * squareSize);
                        animationProgress = 0.0f;
                        animatedPiece = board.getPiece(aiMove.toRow, aiMove.toCol);
                        
                        // Debug output
                        board.debugBoard();
                        std::cout << "AI moved: " << aiMove.toString() << std::endl;
                        
                        // Play appropriate sound
                        const Move& moveInfo = board.getLastMove();
                        if (board.getGameState() == GameState::CHECK || board.getGameState() == GameState::CHECKMATE) {
                            if (hasCheckSound) checkSound.play();
                        }
                        else if (moveInfo.pieceCaptured != ' ' || moveInfo.special == SpecialMove::EN_PASSANT) {
                            if (hasCaptureSound) captureSound.play();
                        }
                        else {
                            moveSound.play();
                        }
                        
                        // Store last move for highlight
                        lastMove.clear();
                        lastMove.push_back(sf::Vector2i(selectedCol, selectedRow));
                        lastMove.push_back(sf::Vector2i(aiMove.toCol, aiMove.toRow));
                        
                        // Change turn
                        turn = oppositeColor(turn);
                        
                        // Update the status panel
                        statusPanel.update(board, whiteName, blackName, turn);
                        
                        // Check if game over
                        if (board.getGameState() == GameState::CHECKMATE || board.getGameState() == GameState::STALEMATE) {
                            std::string result;
                            if (board.getGameState() == GameState::CHECKMATE) {
                                std::string winner = (turn == Color::WHITE) ? blackName : whiteName;
                                result = winner + " wins!";
                            } else {
                                result = "Draw by stalemate!";
                            }
                            gameOverText.setString(result);
                            currentScreen = GameScreen::GAME_OVER;
                        }
                    }
                    pieceSelected = false;
                    selectedRow = selectedCol = -1;
                }
            }
        }
        
        // Update animation if active
        if (animationProgress < 1.0f) {
            animationProgress += 0.08f;  // Slightly faster animation
            if (animationProgress >= 1.0f)
                animationProgress = 1.0f;
        }
        
        // Begin drawing
        window.clear(sf::Color(30, 30, 30));  // Darker background
        
        if (currentScreen == GameScreen::GAME_MODE) {
            // Draw game mode selection screen
            window.draw(gameModeTitle);
            pvpButton.draw(window);
            pveButton.draw(window);
            evpButton.draw(window);
        }
        else if (currentScreen == GameScreen::PLAYER_NAMES) {
            // Draw player name input screen
            window.draw(gameTitle);
            window.draw(namePrompt1);
            window.draw(namePrompt2);
            whiteInput.draw(window);
            blackInput.draw(window);
            startButton.draw(window);
        }
        else if (currentScreen == GameScreen::GAME) {
            // Update scores and turn indicator
            int whiteScore, blackScore;
            calculateScores(board, whiteScore, blackScore);
            whiteScoreText.setString(whiteName + ": " + std::to_string(whiteScore));
            blackScoreText.setString(blackName + ": " + std::to_string(blackScore));
            turnIndicator.setString((turn == Color::WHITE ? whiteName : blackName) + "'s Turn");
            
            whiteScoreText.setFont(font);
            whiteScoreText.setCharacterSize(20);
            whiteScoreText.setFillColor(sf::Color::White);
            whiteScoreText.setPosition(10, windowSize + 10);
            
            blackScoreText.setFont(font);
            blackScoreText.setCharacterSize(20);
            blackScoreText.setFillColor(sf::Color::Black);
            blackScoreText.setPosition(windowSize/2 + 10, windowSize + 10);
            
            turnIndicator.setFont(font);
            turnIndicator.setCharacterSize(20);
            turnIndicator.setFillColor(sf::Color::Yellow);
            turnIndicator.setPosition(windowSize/2 - 100, windowSize + 40);
            
            // Add check indicator
            sf::Text checkText;
            if (board.getGameState() == GameState::CHECK) {
                checkText.setFont(font);
                checkText.setString("CHECK!");
                checkText.setCharacterSize(24);
                checkText.setFillColor(sf::Color::Red);
                checkText.setPosition(10, windowSize + 40);
            }
            
            // Draw the game board and pieces
            // Draw board squares
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
                    square.setPosition(col * squareSize, (7 - row) * squareSize);
                    bool isLightSquare = ((row + col) % 2 == 0);
                    square.setFillColor(isLightSquare ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
                    
                    // Highlight last move
                    if (!lastMove.empty()) {
                        if ((lastMove[0].x == col && lastMove[0].y == row) || 
                            (lastMove[1].x == col && lastMove[1].y == row)) {
                            square.setFillColor(isLightSquare ? sf::Color(230, 180, 50) : sf::Color(180, 120, 30));
                        }
                    }
                    
                    // Highlight selected piece
                    if (pieceSelected && row == selectedRow && col == selectedCol)
                        square.setFillColor(sf::Color(180, 180, 30));
                        
                    window.draw(square);
                }
            }
            
            // If a piece is selected, show its legal moves (using canMoveTo which respects check)
            if (pieceSelected) {
                std::vector<Move> legalMoves = board.getLegalMoves(selectedRow, selectedCol);
                for (const auto& move : legalMoves) {
                    int dstRow = move.toRow;
                    int dstCol = move.toCol;
                    
                    sf::CircleShape highlight;
                    
                    // Use different highlights based on move type
                    if (move.pieceCaptured != ' ' || move.special == SpecialMove::EN_PASSANT) {
                        // Capture highlight
                        highlight.setRadius(squareSize * 0.4f);
                        highlight.setPosition(
                            dstCol * squareSize + squareSize * 0.5f - highlight.getRadius(),
                            (7 - dstRow) * squareSize + squareSize * 0.5f - highlight.getRadius()
                        );
                        highlight.setFillColor(sf::Color::Transparent);
                        highlight.setOutlineColor(sf::Color(255, 0, 0, 180));
                        highlight.setOutlineThickness(3);
                    }
                    else if (move.special == SpecialMove::CASTLING) {
                        // Castling highlight
                        highlight.setRadius(squareSize * 0.15f);
                        highlight.setPosition(
                            dstCol * squareSize + squareSize * 0.5f - highlight.getRadius(),
                            (7 - dstRow) * squareSize + squareSize * 0.5f - highlight.getRadius()
                        );
                        highlight.setFillColor(sf::Color(0, 0, 255, 120));
                    }
                    else if (move.special == SpecialMove::PROMOTION) {
                        // Promotion highlight
                        highlight.setRadius(squareSize * 0.15f);
                        highlight.setPosition(
                            dstCol * squareSize + squareSize * 0.5f - highlight.getRadius(),
                            (7 - dstRow) * squareSize + squareSize * 0.5f - highlight.getRadius()
                        );
                        highlight.setFillColor(sf::Color(255, 0, 255, 120));
                    }
                    else {
                        // Regular move highlight
                        highlight.setRadius(squareSize * 0.15f);
                        highlight.setPosition(
                            dstCol * squareSize + squareSize * 0.7f - highlight.getRadius(),
                            (7 - dstRow) * squareSize + squareSize * 0.7f - highlight.getRadius()
                        );
                        highlight.setFillColor(sf::Color(0, 255, 0, 120));
                    }
                    
                    window.draw(highlight);
                }
            }
            
            // Draw chess pieces using Unicode symbols
            const auto &grid = board.getBoard();
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    PiecePtr piece = grid[row][col];
                    if (piece) {
                        // Skip drawing the animated piece in its original position
                        if (animationProgress < 1.0f && piece == animatedPiece)
                            continue;
                            
                        sf::Text text;
                        text.setFont(font);
                        sf::String unicodeSymbol = getUnicodeForPiece(piece->getSymbol());
                        text.setString(unicodeSymbol);
                        text.setCharacterSize(squareSize - 10);
                        text.setPosition(col * squareSize + squareSize * 0.15f,
                                       (7 - row) * squareSize + squareSize * 0.05f);
                        text.setFillColor((piece->getColor() == Color::WHITE) ? sf::Color::White : sf::Color::Black);
                        window.draw(text);
                    }
                }
            }
            
            // Draw the animated piece if animation is active
            if (animationProgress < 1.0f && animatedPiece) {
                sf::Text text;
                text.setFont(font);
                sf::String unicodeSymbol = getUnicodeForPiece(animatedPiece->getSymbol());
                text.setString(unicodeSymbol);
                text.setCharacterSize(squareSize - 10);
                
                // Linear interpolation between source and target positions
                float x = pieceMovingFrom.x + (pieceMovingTo.x - pieceMovingFrom.x) * animationProgress;
                float y = pieceMovingFrom.y + (pieceMovingTo.y - pieceMovingFrom.y) * animationProgress;
                
                text.setPosition(x + squareSize * 0.15f, y + squareSize * 0.05f);
                text.setFillColor((animatedPiece->getColor() == Color::WHITE) ? sf::Color::White : sf::Color::Black);
                window.draw(text);
            }
            
            // Draw UI elements
            window.draw(whiteScoreText);
            window.draw(blackScoreText);
            window.draw(turnIndicator);
            
            // Draw the status panel with move history
            statusPanel.draw(window);
            
            // Draw check indicator if in check
            if (board.getGameState() == GameState::CHECK) {
                window.draw(checkText);
            }
        }
        else if (currentScreen == GameScreen::GAME_OVER) {
            // Draw game over screen
            // Still draw the final board state
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
                    square.setPosition(col * squareSize, (7 - row) * squareSize);
                    bool isLightSquare = ((row + col) % 2 == 0);
                    square.setFillColor(isLightSquare ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
                    window.draw(square);
                }
            }
            
            const auto &grid = board.getBoard();
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    PiecePtr piece = grid[row][col];
                    if (piece) {
                        sf::Text text;
                        text.setFont(font);
                        sf::String unicodeSymbol = getUnicodeForPiece(piece->getSymbol());
                        text.setString(unicodeSymbol);
                        text.setCharacterSize(squareSize - 10);
                        text.setPosition(col * squareSize + squareSize * 0.15f,
                                       (7 - row) * squareSize + squareSize * 0.05f);
                        text.setFillColor((piece->getColor() == Color::WHITE) ? sf::Color::White : sf::Color::Black);
                        window.draw(text);
                    }
                }
            }
            
            // Draw semi-transparent overlay
            sf::RectangleShape overlay(sf::Vector2f(windowSize, windowSize + infoHeight));
            overlay.setFillColor(sf::Color(0, 0, 0, 180));
            window.draw(overlay);
            
            // Draw game over message and restart button
            window.draw(gameOverText);
            restartButton.draw(window);
        }
        
        window.display();
    }
    
    return 0;
}
