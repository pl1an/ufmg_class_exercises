import matplotlib.pyplot as plt
import math


class FractalPlotter:
    # important data for generation
    def __init__(self, turn_value_degrees):
        self.generation_string = ""
        with open("fractal_string.txt", "r") as file:
            self.generation_string = file.read()
        self.base_lenght = 1000
        self.stroke_angle = 0
        self.turn_value_degrees = turn_value_degrees

    # calculates the lenght of each stroke
    def calculate_segment(self, base_lenght):
        segment_number = 1
        for i in self.generation_string:
            if i=="f" or i=="F":
                segment_number+=1
        self.base_lenght = self.base_lenght/segment_number
        return base_lenght

    # returns a new point in the end of the stroke
    def stroke(self, initial_x, initial_y, angle):
        new_x = initial_x + self.base_lenght*math.cos(math.radians(angle))
        new_y = initial_y + self.base_lenght*math.sin(math.radians(angle))
        return [new_x, new_y]

    # generating data
    def generate_plot(self):
        data = {"x":[0], "y":[0]}
        for i in self.generation_string:
            if i=="f" or i=="F":
                new_points = self.stroke(data["x"][-1], data["y"][-1], self.stroke_angle)
                data["x"].append(new_points[0])
                data["y"].append(new_points[1])
            if i=="+":
                self.stroke_angle = (self.stroke_angle + self.turn_value_degrees) % 360
            if i=="-":
                self.stroke_angle = (self.stroke_angle - self.turn_value_degrees) % 360
        return data

    # creating plot
    def make_plot(self, data):
        plt.plot(data["x"], data["y"], color="black")
        manager = plt.get_current_fig_manager()
        manager.full_screen_toggle()
        plt.axis("equal")
        plt.xlabel("X-axis Label")
        plt.ylabel("Y-axis Label")
        plt.title("Fractal")
        plt.show()


    # main application
    def show_plot(self):
        self.base_lenght = self.calculate_segment(self.base_lenght)
        data = self.generate_plot()
        self.make_plot(data)
