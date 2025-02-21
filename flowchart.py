from reportlab.lib.pagesizes import A4
from reportlab.lib import colors
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
import math

def draw_box(c, x, y, width, height, title, bullets, fill_color):
    """
    Draws a rectangle with a title and bullet points.
    (x, y) is the bottom-left corner.
    """
    # Draw the filled rectangle
    c.setFillColor(fill_color)
    c.setStrokeColor(colors.black)
    c.setLineWidth(1)
    c.rect(x, y, width, height, fill=1, stroke=1)
    
    # Draw the title (centered at top)
    c.setFillColor(colors.black)
    c.setFont("Helvetica-Bold", 12)
    c.drawCentredString(x + width/2, y + height - 15, title)
    
    # Draw bullet points
    c.setFont("Helvetica", 10)
    bullet_y = y + height - 30
    for bullet in bullets:
        c.drawString(x + 10, bullet_y, u"\u2022 " + bullet)
        bullet_y -= 12

def draw_arrow(c, start_x, start_y, end_x, end_y):
    """
    Draws an arrow from (start_x, start_y) to (end_x, end_y)
    with a filled triangular arrowhead.
    """
    c.setStrokeColor(colors.black)
    c.setLineWidth(1.5)
    c.line(start_x, start_y, end_x, end_y)
    
    # Calculate angle for arrowhead
    angle = math.atan2(end_y - start_y, end_x - start_x)
    arrow_length = 8
    arrow_width = 4
    left_x = end_x - arrow_length * math.cos(angle) + arrow_width * math.sin(angle)
    left_y = end_y - arrow_length * math.sin(angle) - arrow_width * math.cos(angle)
    right_x = end_x - arrow_length * math.cos(angle) - arrow_width * math.sin(angle)
    right_y = end_y - arrow_length * math.sin(angle) + arrow_width * math.cos(angle)
    
    p = c.beginPath()
    p.moveTo(end_x, end_y)
    p.lineTo(left_x, left_y)
    p.lineTo(right_x, right_y)
    p.close()
    c.drawPath(p, fill=1, stroke=0)

def generate_flowchart_pdf(pdf_filename):
    """
    Generates a PDF flowchart with the following structure:
    
    1. User Interaction Layer (Frontend)
       • User visits the platform
       • Enters crane specifications or selects predefined models
       • Compares features, prices, and performance
       • Gets recommendations based on ML algorithms
       • Can save and download reports
       
    2. Backend Processing (Firebase & ML Models)
       • Processes user input
       • Fetches data from Firebase (crane specs, past performance, user reviews)
       • ML-based recommendation engine
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
       • Suggests best option based on cost and load capacity
    """
    c = canvas.Canvas(pdf_filename, pagesize=A4)
    page_width, page_height = A4

    # Define each flowchart layer with title, bullet points, and a distinct fill color.
    layers = [
        {
            "title": "User Interaction Layer (Frontend)",
            "bullets": [
                "User visits the platform",
                "Enters crane specifications or selects predefined models",
                "Compares features, prices, and performance",
                "Gets recommendations based on ML algorithms",
                "Can save and download reports"
            ],
            "fill_color": colors.lavender
        },
        {
            "title": "Backend Processing (Firebase & ML Models)",
            "bullets": [
                "Processes user input",
                "Fetches data from Firebase",
                "ML-based recommendation engine",
                "Stores user preferences and search history"
            ],
            "fill_color": colors.lightgreen
        },
        {
            "title": "Database (Firebase Firestore)",
            "bullets": [
                "Stores crane data (types, load capacity, price, reviews)",
                "Stores user interaction history",
                "Manages authentication & permissions"
            ],
            "fill_color": colors.lightyellow
        },
        {
            "title": "IoT & Hardware Integration (Optional)",
            "bullets": [
                "Sensor data from real cranes for real-time monitoring",
                "IoT modules (Arduino/Raspberry Pi) collect data",
                "Data sent to Firebase for analysis"
            ],
            "fill_color": colors.orange
        },
        {
            "title": "Decision Support System",
            "bullets": [
                "Compares crane parameters using analytics",
                "Provides visualization (charts, graphs)",
                "Suggests best option based on cost and load capacity"
            ],
            "fill_color": colors.lightblue
        }
    ]

    # Set box dimensions and layout parameters.
    box_width = 450
    box_height = 100
    gap = 40  # vertical gap between boxes
    start_y = page_height - 100  # starting y (top margin)
    start_x = (page_width - box_width) / 2  # centered horizontally

    # Store positions for drawing arrows.
    positions = []

    # Draw each layer's box.
    for layer in layers:
        draw_box(c, start_x, start_y - box_height, box_width, box_height, 
                 layer["title"], layer["bullets"], layer["fill_color"])
        positions.append((start_x, start_y - box_height, box_width, box_height))
        start_y -= box_height + gap

    # Draw arrows connecting the boxes vertically.
    for i in range(len(positions) - 1):
        x, y, width, height = positions[i]
        next_x, next_y, nwidth, nheight = positions[i+1]
        arrow_start_x = x + width/2
        arrow_start_y = y  # bottom center of the current box
        arrow_end_x = next_x + nwidth/2
        arrow_end_y = next_y + nheight  # top center of the next box
        draw_arrow(c, arrow_start_x, arrow_start_y, arrow_end_x, arrow_end_y)

    c.showPage()
    c.save()
    print("PDF saved as", pdf_filename)

if __name__ == "__main__":
    generate_flowchart_pdf("Clear_Flowchart.pdf")
