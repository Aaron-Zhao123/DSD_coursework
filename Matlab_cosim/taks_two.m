%test case 1,2,3
N = [52, 2551, 255001];
step = [5 0.1 0.001];

Case_num = 3;

x_value_one(1) = single(0);
for i = 2:N(1)
    x_value_one(i)=single(x_value_one(i-1)) + single(step(1));
end

x_value_two(1) = 0;
for i = 2:N(2)
    x_value_two(i)=x_value_two(i-1) + step(2);
end

x_value_three(1) = 0;
for i = 2:N(3)
    x_value_three(i)=x_value_three(i-1) + step(2);
end

y_vec_one = single(x_value_one) + single(x_value_one).^2;
y_vec_two = x_value_two + x_value_two.^2;
y_vec_three = x_value_three + x_value_three.^2;

y_value_one = sum(single(y_vec_one));
y_value_two = sum(y_vec_two);
y_value_three = sum(y_vec_three);

y_val_one = 0;
for i = 1:N(1)
    y_val_one = y_val_one + x_value_one(i)+ x_value_one(i) * x_value_one(i);
end

y_val_two = 0;
for i = 1:N(2)
    y_val_two = y_val_two + x_value_two(i)+ x_value_two(i) * x_value_two(i);
end

y_val_three = 0;
for i = 1:N(3)
    y_val_three = y_val_three + x_value_three(i)+ x_value_three(i) * x_value_three(i);
end