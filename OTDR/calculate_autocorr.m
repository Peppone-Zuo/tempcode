function auto_series = calculate_autocorr(series)

auto_series = zeros(1, length(series));

for k = 0 : (length(series) - 1)
    for j = 0 : (length(series) - k -1)
        auto_series(k + 1) = auto_series(k + 1) + series(j + 1) * series(j + 1 + k);
    end
end
