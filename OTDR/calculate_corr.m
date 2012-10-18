function corr = calculate_corr(series1, series2)

corr = zeros(1, length(series1));

for k = 0 : (length(series1) - 1)
    for j = 0 : (length(series1) - k -1)
        corr(k + 1) = corr(k + 1) + series1(j + 1) * series2(j + 1 + k);
    end
end
