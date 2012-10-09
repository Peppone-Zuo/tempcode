function [A, B] = generate_golay_codes(N)

A = [1 ,1];
B = [1, -1];
for k = 1 : N - 1
    a = A;
    A = [A, B];
    B = [a, B * (-1)];
end
