This is a file that contains notes for my datascience for programming course for uni.

### Metrics for Regression
1. Mean Squared Error
2. Root Mean Squared Error (RMSE)
3. Mean Absolute Error (MAE)
4. r2 score
  - best score 1.0, can be negative.




### K-NN
Model based learning (eager)
- training phase: build a model using training data
- prediction phase: use the model to make predictions
- <img width="289" alt="Screen Shot 2022-09-07 at 2 12 21 PM" src="https://user-images.githubusercontent.com/8170405/188793775-88bb4386-cb5f-4d8c-92b1-8b29b667a5ed.png">
Instance based learning (lazy)

- training phase: do nothing
- prediction phase: compare new instances with training data to make predictions
- <img width="278" alt="Screen Shot 2022-09-07 at 2 12 39 PM" src="https://user-images.githubusercontent.com/8170405/188793811-f586e4a8-8de7-4a2c-aa23-ad95b0dde568.png">

- The kNN algorithm simply stores the training dataset.
- To make a prediction for a new data point, the algorithm finds the closest data
points in the training dataset — its “nearest neighbors.”
- The prediction is an aggregation of the known outputs for the nearest neighbors.
  - Example: 
  - For classification , the prediction is the majority class among the relevant neighbors. 
  - For regression , the prediction is the average of the relevant neighbors’ labels
