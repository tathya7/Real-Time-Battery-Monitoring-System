import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import time
import pickle
pickled_model = pickle.load(open('rasberrypi.pkl', 'rb'))

# print(pickled_model.get_booster().feature_names)


while True:
    x=0
    x=x+1
    df = pd.read_csv("DataTest.csv")
    arr = df.iloc[x].values
    row_to_predict = arr.reshape(1, -1)
    df = pd.DataFrame(row_to_predict, columns=pickled_model.feature_names_in_)
    SOC = pickled_model.predict(df)
    print(SOC)
    # if SOC>75:
    #     print("Battery in Excellent Condition")
    # elif 75>=SOC>=50:
    #     print("Battery in Good State")
    # else:
    #     print("Charge Battery As soon as possible")        
    # # print(SOC[0])
    time.sleep(10)
