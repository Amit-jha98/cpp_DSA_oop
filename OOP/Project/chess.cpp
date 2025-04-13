#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <cstdlib>

//------------------------//
//  Core Chess Logic      //
//------------------------//

enum class Color { WHITE, BLACK, NONE };

inline Color oppositeColor(Color c) {
    return (c == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

// Forward declaration
class Board;

class Piece {
public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() = default;
    
    Color getColor() const { return color; }
    virtual char getSymbol() const = 0;
    // Basic move validation. (This doesn’t include check-check or castling.)
    virtual bool isMoveValid(int srcRow, int srcCol, int dstRow, int dstCol, const Board& board) const = 0;
    
protected:
    Color color;
};

using PiecePtr = std::shared_ptr<Piece>;

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
    bool movePiece(int srcRow, int srcCol, int dstRow, int dstCol, Color turn) {
        if (!inBounds(srcRow, srcCol) || !inBounds(dstRow, dstCol))
            return false;
        PiecePtr p = board[srcRow][srcCol];
        if (!p) return false;
        if (p->getColor() != turn) return false;
        if (!p->isMoveValid(srcRow, srcCol, dstRow, dstCol, *this))
            return false;
        PiecePtr dstPiece = board[dstRow][dstCol];
        if (dstPiece && dstPiece->getColor() == turn)
            return false;
        board[dstRow][dstCol] = p;
        board[srcRow][srcCol] = nullptr;
        return true;
    }
    
    bool inBounds(int row, int col) const {
        return (row >= 0 && row < 8 && col >= 0 && col < 8);
    }
    
    const std::vector<std::vector<PiecePtr>>& getBoard() const {
        return board;
    }
    
private:
    std::vector<std::vector<PiecePtr>> board;
    void setupBoard();
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
    Pawn(Color color) : Piece(color), hasMoved(false) {}
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
        return false;
    }
    void markMoved() { hasMoved = true; }
    
private:
    bool hasMoved;
};

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
//  Helper: Unicode Icons //
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

//------------------------//
//  Get Possible Moves    //
//------------------------//

// Iterates over all board squares to check if the given piece at (srcRow,srcCol)
// can move to a square. This is a simple approach and does not check for check conditions.
std::vector<sf::Vector2i> getPossibleMoves(const Board& board, int srcRow, int srcCol) {
    std::vector<sf::Vector2i> moves;
    PiecePtr p = board.getPiece(srcRow, srcCol);
    if (!p) return moves;
    for (int dstRow = 0; dstRow < 8; ++dstRow) {
        for (int dstCol = 0; dstCol < 8; ++dstCol) {
            if (!board.inBounds(dstRow, dstCol)) continue;
            // Skip destination that has a piece of the same color.
            PiecePtr destPiece = board.getPiece(dstRow, dstCol);
            if (destPiece && destPiece->getColor() == p->getColor())
                continue;
            if (p->isMoveValid(srcRow, srcCol, dstRow, dstCol, board)) {
                moves.push_back(sf::Vector2i(dstCol, dstRow));
            }
        }
    }
    return moves;
}

//------------------------//
//  SFML UI Implementation//
//------------------------//

int main() {
    const int windowSize = 640;
    const int infoHeight = 50;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize + infoHeight), "2-Player Chess Game");
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
    sf::SoundBuffer moveBuffer;
    if (!moveBuffer.loadFromFile("move.wav")) {
        std::cerr << "move.wav not found. Continuing without sound.\n";
    }
    sf::Sound moveSound;
    moveSound.setBuffer(moveBuffer);
    
    // Initialize game state
    Board board;
    Color turn = Color::WHITE;
    bool pieceSelected = false;
    int selectedRow = -1, selectedCol = -1;
    const int squareSize = windowSize / 8;  // 8x8 board
    
    // Info texts (scores, turn indicator)
    sf::Text whiteScoreText, blackScoreText, turnIndicator;
    whiteScoreText.setFont(font);
    whiteScoreText.setCharacterSize(20);
    whiteScoreText.setFillColor(sf::Color::White);
    whiteScoreText.setPosition(10, windowSize + 5);
    
    blackScoreText.setFont(font);
    blackScoreText.setCharacterSize(20);
    blackScoreText.setFillColor(sf::Color::Black);
    blackScoreText.setPosition(windowSize/2 + 10, windowSize + 5);
    
    turnIndicator.setFont(font);
    turnIndicator.setCharacterSize(20);
    turnIndicator.setFillColor(sf::Color::Yellow);
    turnIndicator.setPosition(windowSize/2 - 50, windowSize + 5);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Handle mouse clicks to select/move pieces
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int col = event.mouseButton.x / squareSize;
                int row = 7 - (event.mouseButton.y / squareSize);
                
                if (!pieceSelected) {
                    PiecePtr p = board.getPiece(row, col);
                    if (p && p->getColor() == turn) {
                        pieceSelected = true;
                        selectedRow = row;
                        selectedCol = col;
                    }
                } else {
                    bool moved = board.movePiece(selectedRow, selectedCol, row, col, turn);
                    if (moved) {
                        PiecePtr movedPiece = board.getPiece(row, col);
                        if (movedPiece) {
                            Pawn* pawn = dynamic_cast<Pawn*>(movedPiece.get());
                            if (pawn)
                                pawn->markMoved();
                        }
                        if (moveBuffer.getDuration() != sf::Time::Zero)
                            moveSound.play();
                        turn = oppositeColor(turn);
                    }
                    pieceSelected = false;
                    selectedRow = selectedCol = -1;
                }
            }
        }
        
        // Update scores and turn indicator
        int whiteScore, blackScore;
        calculateScores(board, whiteScore, blackScore);
        whiteScoreText.setString("White Score: " + std::to_string(whiteScore));
        blackScoreText.setString("Black Score: " + std::to_string(blackScore));
        turnIndicator.setString((turn == Color::WHITE) ? "White's Turn" : "Black's Turn");
        
        // Begin drawing
        window.clear();
        
        // Draw board squares
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
                square.setPosition(col * squareSize, (7 - row) * squareSize);
                bool isLightSquare = ((row + col) % 2 == 0);
                square.setFillColor(isLightSquare ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
                // Highlight if selected
                if (pieceSelected && row == selectedRow && col == selectedCol)
                    square.setFillColor(sf::Color::Yellow);
                window.draw(square);
            }
        }
        
        // If a piece is selected, show possible moves (as translucent green overlays)
        if (pieceSelected) {
            std::vector<sf::Vector2i> moves = getPossibleMoves(board, selectedRow, selectedCol);
            for (const auto& move : moves) {
                sf::RectangleShape highlight(sf::Vector2f(squareSize, squareSize));
                // In our coordinate conversion, (col, row): row counted from bottom
                highlight.setPosition(move.x * squareSize, (7 - move.y) * squareSize);
                highlight.setFillColor(sf::Color(0, 255, 0, 100));
                window.draw(highlight);
            }
        }
        
        // Draw chess pieces using Unicode symbols
        const auto &grid = board.getBoard();
// In your drawing loop:
for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
        PiecePtr piece = grid[row][col];
        if (piece) {
            sf::Text text;
            text.setFont(font);
            // Use the updated Unicode helper function:
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

        // Draw UI info texts
        window.draw(whiteScoreText);
        window.draw(blackScoreText);
        window.draw(turnIndicator);
        
        window.display();
    }
    
    return 0;
}
