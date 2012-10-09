clear all; clc; clear;

step = 0.1;
total_points = 10000;

index = step : step : total_points;
fiber_loss = 0.2;   %0.2dB/km


power_when_propogate = zeros(1, length(index));
for k = 1 : length(index)
    power_when_propogate(k) = power_when_propogate(k) - (k/1000) * fiber_loss;
end
% figure(1);
% plot(power_when_propogate);


power_when_detect = power_when_propogate;
for k = 1 : length(index)
    power_when_detect(k) = power_when_detect(k) - (k/1000) * fiber_loss;
end
% figure(2);
% plot(power_when_detect);

[A, B] = generate_golay_codes(6);
sum = calculate_autocorr(A) + calculate_autocorr(B);

% figure(1);
% subplot(3, 1, 1);
% plot(calculate_autocorr(A));
% subplot(3, 1, 2);
% plot(calculate_autocorr(B));
% subplot(3, 1, 3);
% plot(calculate_autocorr(sum));
% 
% figure(2);
% plot(calculate_autocorr(A));

pulse_response = zeros(1, 10000);
for k = 1 : length(pulse_response)
    if k < 500
        pulse_response(k) = k;
    else
        pulse_response(k) = 500 - 0.05 * (k - 500);
    end
end


shift = 1000;


figure(1);
plot(pulse_response);
axis([0 11000 0 600]);
grid on;


multi_response = pulse_response;
for k = 1 : 5
    multi_response = multi_response + [zeros(1, k * shift) pulse_response(1 : (10000 - k * shift))];
end



figure(2);
plot(multi_response);





