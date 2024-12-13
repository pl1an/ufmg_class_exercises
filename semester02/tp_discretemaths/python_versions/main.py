from plotter import FractalPlotter


def generate_fractal_string():
    # important variables
    rules = {"F":"F+F-F-FFF+F+F-F"}
    base = "F+F+F+F"
    angle = 90
    remove_symbols = "YX"
    recursion_level = 4
    base1 = base
    # generation loop
    for i in range(0, recursion_level):
        # applying rules]
        ii = 0
        while(ii<len(base1)):
            try:
                rule = rules[base1[ii]]
                base1 = base1[:ii] + rule + base1[(ii+1):]
                ii += len(rule)-1
            except KeyError:
                pass
            ii+=1
    # removing characters
    i=0
    while(i<len(base1)):
        for ii in remove_symbols:
            if base1[i] == ii:
                base1 = base1[:i] + base1[(i+1):]
                i -= 1
        i+=1
    # storing result in file
    with open("fractal_string.txt", "w") as file:
        file.write(base1)


#generate_fractal_string()
plotter = FractalPlotter(90)
plotter.show_plot()