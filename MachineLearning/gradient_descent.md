Python implementation for lineare regression with gradient descent
```
#Y=kx+b
#k-> k-Partial derivative of k  
#b -> b - Partial derivative of b  

import numpy as np
import matplotlib.pyplot as plt

# Generate sample data using np.linspace()
X = np.linspace(1, 10, num=10, dtype=float)  # Generates 10 evenly spaced values from 1 to 10
Y = 2 * X + 3 + np.random.randn(len(X)) * 0.5


# Initialize parameters randomly
k = np.random.randn()  # Initial slope
b = np.random.randn()  # Initial intercept

# Hyperparameters
learning_rate = 0.01
num_iterations = 1000  # More iterations for better convergence
n = len(X)  # Number of data points

# Gradient Descent Loop
for i in range(num_iterations):
    # Compute predictions
    Y_pred = k * X + b
    
    # Compute gradients
    dm = (2/n) * np.sum((Y_pred - Y) * X)  # Partial derivative w.r.t m
    db = (2/n) * np.sum(Y_pred - Y)       # Partial derivative w.r.t b
    
    # Update parameters
    k -= learning_rate * dm
    b -= learning_rate * db

# Print final values
print(f"Final k (slope): {k:.5f}")  # Should be close to 2
print(f"Final b (intercept): {b:.5f}")  # Should be close to 3

# Visualization
plt.figure(figsize=(8, 6))
plt.scatter(X, Y, color="blue", label="Actual Data")  # Scatter plot of real data
plt.plot(X, k * X + b, color="red", label="Fitted Line")  # Regression line after gradient descent
plt.xlabel("Feature (X)")
plt.ylabel("Target (Y)")
plt.title("Linear Regression with Gradient Descent")
plt.legend()
plt.grid()
plt.show()



```
