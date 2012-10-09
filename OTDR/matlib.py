import matplotlib.pyplot as plt
from matplotlib.pyplot import *
radius = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]
area = [3.14159, 12.56636, 28.27431, 50.26544, 78.53975, 113.09724]
square = [1.0, 4.0, 9.0, 16.0, 25.0, 36.0]
#plot(radius, area, label='Circle')
#plot(radius, square, marker='o', linestyle='--', color='r', label='Square')
plot([1, 2, 3, 5, 8])
xlabel('Radius/Side')
ylabel('Area')
title('Area of Shapes')
grid(True)
my_plot = gca()
#legend()
print my_plot
line = my_plot.lines[0]
line
show()

