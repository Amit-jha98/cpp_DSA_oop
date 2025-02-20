from reportlab.lib.pagesizes import A4
from reportlab.lib import colors
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
import math

def draw_flowchart_box(c, x, y, width, height, title, bullets, fill_color, stroke_color=colors.black):
    """
    Draws a rounded rectangle with a drop shadow, title, and bullet points.
    Parameters:
      c: canvas object
      (x, y): bottom-left corner of the box
      width, height: dimensions of the box
      title: string title (centered)
      bullets: list of bullet strings
      fill_color: the fill color (e.g. colors.Color(r, g, b))
      stroke_color: the border color
    """
    # Draw drop shadow
    shadow_offset = 3
    c.setFillColor(colors.grey)
    c.roundRect(x + shadow_offset, y - shadow_offset, width, height, 10, fill=1, stroke=0)
    
    # Draw the main box with rounded corners
    c.setFillColor(fill_color)
    c.setStrokeColor(stroke_color)
    c.setLineWidth(1)
    c.roundRect(x, y, width, height, 10, fill=1, stroke=1)
    
    # Draw title text (centered)
    c.setFillColor(colors.black)
    c.setFont("Helvetica-Bold", 14)
    title_y = y + height - 20  # 20 pts margin from top
    c.drawCentredString(x + width/2, title_y, title)
    
    # Draw bullet points with a small indent
    c.setFont("Helvetica", 10)
    bullet_y = title_y - 20
    for bullet in bullets:
        bullet_text = u"\u2022 " + bullet  # bullet character
        c.drawString(x + 15, bullet_y, bullet_text)
        bullet_y -= 14  # line spacing

def draw_arrow(c, start_x, start_y, end_x, end_y):
    """
    Draws an arrow from (start_x, start_y) to (end_x, end_y) with a filled triangle arrowhead.
    """
    c.setLineWidth(1.5)
    c.setStrokeColor(colors.black)
    c.line(start_x, start_y, end_x, end_y)
    
    # Calculate angle for the arrowhead
    angle = math.atan2(end_y - start_y, end_x - start_x)
    arrow_length = 10
    arrow_width = 5
    # Calculate the two side points of the arrowhead
    left_x = end_x - arrow_length * math.cos(angle) + arrow_width * math.sin(angle)
    left_y = end_y - arrow_length * math.sin(angle) - arrow_width * math.cos(angle)
    right_x = end_x - arrow_length * math.cos(angle) - arrow_width * math.sin(angle)
    right_y = end_y - arrow_length * math.sin(angle) + arrow_width * math.cos(angle)
    
    # Draw a filled triangle as arrowhead using a path
    p = c.beginPath()
    p.moveTo(end_x, end_y)
    p.lineTo(left_x, left_y)
    p.lineTo(right_x, right_y)
    p.close()
    c.setFillColor(colors.black)
    c.drawPath(p, fill=1, stroke=0)

def generate_flowchart_pdf(pdf_filename):
    """
    Generates an attractive PDF flowchart that represents the following structure:
    
    1. User Interaction Layer (Frontend)
       • User visits the platform
       • Enters crane specifications or selects predefined models
       • Compares features, prices, and performance
       • Gets recommendations based on machine learning algorithms
       • Can save and download reports
       
    2. Backend Processing (Firebase & ML Models)
       • Processes user input
       • Fetches data from Firebase (crane specs, past performance, user reviews)
       • Machine learning-based recommendation engine
       • Stores user preferences and search history
       
    3. Database (Firebase Firestore)
       • Stores crane data (types, load capacity, price, reviews)
       • Stores user interaction history
       • Manages authentication & permissions
       
    4. IoT & Hardware Integration (Optional)
       • Sensor data from real cranes for real-time monitoring
       • IoT modules (Arduino/Raspberry Pi) collect data (e.g., load, efficiency)
       • Data sent to Firebase for analysis
       
    5. Decision Support System
       • Compares crane parameters using analytics
       • Provides visualization (charts, graphs)
       • Suggests the best option based on cost, load capacity, etc.
    """
    c = canvas.Canvas(pdf_filename, pagesize=A4)
    page_width, page_height = A4
    
    # Define each flowchart layer along with a distinct pastel fill color.
    layers = [
        {
            "title": "User Interaction Layer (Frontend)",
            "bullets": [
                "User visits the platform",
                "Enters crane specifications or selects predefined models",
                "Compares features, prices, and performance",
                "Gets recommendations based on machine learning algorithms",
                "Can save and download reports"
            ],
            "fill_color": colors.Color(0.82, 0.91, 0.97)  # light blue
        },
        {
            "title": "Backend Processing (Firebase & ML Models)",
            "bullets": [
                "Processes user input",
                "Fetches data from Firebase (crane specs, past performance, user reviews)",
                "Machine learning-based recommendation engine",
                "Stores user preferences and search history"
            ],
            "fill_color": colors.Color(0.85, 0.95, 0.85)  # light green
        },
        {
            "title": "Database (Firebase Firestore)",
            "bullets": [
                "Stores crane data (types, load capacity, price, reviews)",
                "Stores user interaction history",
                "Manages authentication & permissions"
            ],
            "fill_color": colors.Color(0.98, 0.97, 0.82)  # light yellow
        },
        {
            "title": "IoT & Hardware Integration (Optional)",
            "bullets": [
                "Sensor data from real cranes for real-time monitoring",
                "IoT modules (Arduino/Raspberry Pi) collect data (e.g., load, efficiency)",
                "Data sent to Firebase for analysis"
            ],
            "fill_color": colors.Color(0.98, 0.90, 0.82)  # light orange
        },
        {
            "title": "Decision Support System",
            "bullets": [
                "Compares crane parameters using analytics",
                "Provides visualization (charts, graphs)",
                "Suggests the best option based on cost, load capacity, etc."
            ],
            "fill_color": colors.Color(0.91, 0.88, 0.97)  # light purple
        }
    ]
    
    # Set box dimensions and margins
    box_width = 500
    box_height = 120
    gap = 30  # increased gap between boxes for clarity
    left_margin = (page_width - box_width) / 2
    top_margin = page_height - 50  # top margin
    
    current_y = top_margin
    
    # Draw each layer's box and connect them with arrows
    for idx, layer in enumerate(layers):
        # Draw the box with title and bullet points
        draw_flowchart_box(
            c,
            left_margin,
            current_y - box_height,
            box_width,
            box_height,
            layer["title"],
            layer["bullets"],
            layer["fill_color"]
        )
        
        # Draw an arrow connecting this box to the next one (if not the last box)
        if idx < len(layers) - 1:
            start_x = page_width / 2
            start_y = current_y - box_height
            end_x = page_width / 2
            end_y = current_y - box_height - gap
            draw_arrow(c, start_x, start_y, end_x, end_y)
        
        # Update the y-coordinate for the next box
        current_y = current_y - box_height - gap
    
    # Finalize and save the PDF
    c.showPage()
    c.save()
    print(f"PDF saved as {pdf_filename}")

if __name__ == "__main__":
    generate_flowchart_pdf("Flowchart_Structure_Attractive.pdf")
