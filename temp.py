step = 0.1#laser step is 0.1m
fiber_length = 1000#fiber length is 1km
fiber_loss = 0.2#fiber loss is 0.2dB/km
pulse_width = 5#pulse width is 5ns

pulse_length = 5 * 3 * 10 ** (-1)
pulse_power = 1#pulse power is 1mw

fiber = [0] * int(fiber_length / step + 1)
for position in range(int(pulse_length / step) + 1):
    fiber[position] = pulse_power


print fiber[:100]
