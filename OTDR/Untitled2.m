clc; close all; clear;

[codeA, codeB] = generate_golay_codes(4);

hx = 0.1*ones(1, 400);
%hx(length(hx)/2:length(hx)/2+1) = [1,1];
hx(length(hx)/2) = 1;
hx(length(hx)/4) = 1;
figure_count = 0;

figure_count = figure_count + 1;
figure(figure_count);
plot(hx);

A_response = conv(codeA, hx);
B_response = conv(codeB, hx);



uselessLength = length(codeA);
% A_response = A_response(uselessLength + 1:end-uselessLength);
% B_response = B_response(uselessLength + 1:end-uselessLength);

figure_count = figure_count + 1;
figure(figure_count);
plot(A_response);

%     resA = calculate_corr(A_response(1+k : 8+k), codeA);
%     resB = calculate_corr(B_response(1+k : 8+k), codeB);
resA = xcorr(A_response, codeA);
resB = xcorr(B_response, codeB);
% resA = xcorr(codeA, A_response);
% resB = xcorr(codeB, B_response);




padLength = length(A_response) - length(codeA);
startPosition = padLength + length(codeA) + 1;


figure_count = figure_count + 1;
figure(figure_count);
plot(resA);
%plot(resA(padLength + 1 : end));

figure_count = figure_count + 1;
figure(figure_count);
plot(resB);

addRes = resA + resB;
figure_count = figure_count + 1;
figure(figure_count);
%plot(addRes);
plot(addRes(padLength + length(codeA):end - length(codeA) + 1));




