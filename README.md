# Performance difference between row-based and column-based matrix access

This test is to collect and compare time consumption of SUM operation on 2D
matrix. The test is based on ctimit() macro and the result shows that row-based
matrix access is much faster than column-based access way:

##For 500x500 matrix, row-based access is same as column-based access:
sum_matrix_row_based(matrix[500][500]):
1 loops, 2ms12µs427ns, avg: 2ms12µs427ns per loop

sum_matrix_col_based(matrix[500][500]):
1 loops, 2ms446µs616ns, avg: 2ms446µs616ns per loop


##For 1000x1000 matrix, row-based access is 2 times faster than column-based access:
sum_matrix_row_based(matrix[1000][1000]):
1 loops, 4ms478µs602ns, avg: 4ms478µs602ns per loop

sum_matrix_col_based(matrix[1000][1000]):
1 loops, 9ms864µs586ns, avg: 9ms864µs586ns per loop


##For 2000x2000 matrix, row-based access is 9 times faster than column-based access:
sum_matrix_row_based(matrix[2000][2000]):
1 loops, 12ms724µs163ns, avg: 12ms724µs163ns per loop

sum_matrix_col_based(matrix[2000][2000]):
1 loops, 105ms457µs148ns, avg: 105ms457µs148ns per loop


##For 8000x8000 matrix, row-based access is 15 times faster than column-based access:
sum_matrix_row_based(matrix[8000][8000]):
1 loops, 314ms208µs608ns, avg: 314ms208µs608ns per loop

sum_matrix_col_based(matrix[8000][8000]):
1 loops, 5s269ms211µs634ns, avg: 5s269ms211µs634ns per loop


Note: you can get all above results in one shot by simple command:
size=500; for i in `seq 1 5`; do ./sum_matrix $size; size=$((size * 2)); done
