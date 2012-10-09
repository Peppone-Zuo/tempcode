from matplotlib.pyplot import *

step = 0.1#laser step in m
fiber_length = 10#fiber length in m
fiber_loss = 0.2#fiber loss in dB/km

pulse_power = 0#pulse power in dBm

fiber = [0] * (int(fiber_length/step) + 1)

pulse_power = [pulse_power - (fiber_loss * step * i / 1000) for i in range(len(fiber))]


pulse_power_when_detect = [power - (fiber_loss * step * index / 1000)\
        for (index, power) in enumerate(pulse_power)]


print "power when propogation"
for index, power in enumerate(pulse_power):
    print float(power), index
print "power when detect"
for index, power in enumerate(pulse_power_when_detect):
    print float(power), index

plot(pulse_power_when_detect)
plot(pulse_power)
clf()

x = range(100)

linear = range(100)

square = []


