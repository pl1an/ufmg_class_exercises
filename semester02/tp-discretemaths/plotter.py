import matplotlib.pyplot as plt
import math


# important data for generation
generation_string = ""
with open("fractal_string.txt", "r") as file:
    generation_string = file.read()
base_lenght = 1000
stroke_angle = 0
turn_value_degrees = 90


# calculates the lenght of each stroke
def calculate_segment(base_lenght):
    segment_number = 1
    for i in generation_string:
        if i=="f" or i=="F":
            segment_number+=1
    base_lenght = base_lenght/segment_number
    return base_lenght


# returns a new point in the end of the stroke
def stroke(base_lenght, initial_x, initial_y, angle):
    new_x = initial_x + base_lenght*math.cos(math.radians(angle))
    new_y = initial_y + base_lenght*math.sin(math.radians(angle))
    return [new_x, new_y]


# generating data
def generate_plot(stroke_angle):
    data = {"x":[0], "y":[0]}
    for i in generation_string:
        if i=="f" or i=="F":
            new_points = stroke(base_lenght, data["x"][-1], data["y"][-1], stroke_angle)
            data["x"].append(new_points[0])
            data["y"].append(new_points[1])
        if i=="+":
            stroke_angle = (stroke_angle - turn_value_degrees) % 360
        if i=="-":
            stroke_angle = (stroke_angle + turn_value_degrees) % 360
    return data


# creating plot
def make_plot(data):
    plt.plot(data["x"], data["y"], label="Prime Numbers", color="black")
    manager = plt.get_current_fig_manager()
    manager.full_screen_toggle()
    plt.axis("equal")
    plt.xlabel("X-axis Label")
    plt.ylabel("Y-axis Label")
    plt.title("Fractal")
    plt.legend()
    plt.show()


# main application
base_lenght = calculate_segment(base_lenght)
data = generate_plot(stroke_angle)
make_plot(data)