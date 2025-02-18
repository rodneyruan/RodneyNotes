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
```
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.axes as ax
from matplotlib.animation import FuncAnimation

url = 'https://media.geeksforgeeks.org/wp-content/uploads/20240320114716/data_for_lr.csv'
data = pd.read_csv(url)
data

# Drop the missing values
data = data.dropna()

# training dataset and labels
train_input = np.array(data.x[0:500]).reshape(500, 1)
train_output = np.array(data.y[0:500]).reshape(500, 1)

# valid dataset and labels
test_input = np.array(data.x[500:700]).reshape(199, 1)
test_output = np.array(data.y[500:700]).reshape(199, 1)

# Y= kX + b
class LinearRegression:
  def __init__(self):
    self.parameters = {}
    self.parameters['k'] = np.random.uniform(0, 1) * -1
    self.parameters['b'] = np.random.uniform(0, 1) * -1


  def forward_propagation(self, train_input):
    k = self.parameters['k']
    b = self.parameters['b']
    predictions = train_input * k + b
    return predictions

  def cost_function(self, predictions, train_output):
    cost = np.mean ( ( predictions - train_output) ** 2 )
    return cost

  def backward_propagation(self, predictions, train_input, train_output):
    partial_derivatives = {}
    partial_derivative_k = np.mean ((predictions - train_output ) * train_input) * 2
    partial_derivative_b = np.mean ((predictions - train_output ) ) * 2
    partial_derivatives['k'] = partial_derivative_k
    partial_derivatives['b'] = partial_derivative_b
    return partial_derivatives

  def update_parameters(self, learning_rate, partial_derivatives):
    self.parameters['k'] -=  learning_rate * partial_derivatives['k']
    self.parameters['b'] -=  learning_rate * partial_derivatives['b']

  def train(self, train_input, train_output, learning_rate, iters): 
    # Initialize random parameters 
    self.parameters['k'] = np.random.uniform(0, 1) * -1
    self.parameters['b'] = np.random.uniform(0, 1) * -1

    self.loss = []
    fig, ax = plt.subplots()
    x_values = np.linspace(min(train_input), max(train_input), 100)
    line, = ax.plot(x_values, x_values* self.parameters['k'] +self.parameters['b'] , color = 'red', label = 'Regression Line')
    ax.scatter(train_input, train_output,marker = 'o', color = 'green', label = 'Training Data')
    ax.set_ylim(0, max(train_output) + 1) 

    def update(frame):
      predictions = self.forward_propagation(train_input)
      cost = self.cost_function(predictions, train_output)
      partial_derivatives = self.backward_propagation(predictions, train_input, train_output)
      self.update_parameters(learning_rate, partial_derivatives)
      line.set_ydata(self.parameters['k'] * x_values + self.parameters['b']) 

      self.loss.append(cost)
      print("Iteration = {}, Loss = {}".format(frame+1, cost))
      return line,
    ani = FuncAnimation(fig, update, frames=iters, interval=200, blit=True) 
    ani.save('linear_regression_A.gif', writer='ffmpeg') 
    plt.xlabel('Input')
    plt.ylabel('Output')
    plt.title('Rodney Test')
    plt.legend()
    plt.show()

    return self.parameters, self.loss
 

linear_reg = LinearRegression()
parameters, loss = linear_reg.train(train_input, train_output, 0.0001, 20)

```
