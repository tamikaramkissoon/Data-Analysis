# Data Analysis

--- 

## Table of Contents
- [Overview](#overview)
- [Description](#description)
- [Lanaguages tools and technologies](#lanaguages-tools-and-technologies)
- [Project](#project)
- [Acknowledgement](#acknowledgement)
- [Author Info](#author-info)

---

## Overview
Ownership of a company is divided into shares or stocks. The shares of publicly traded companies can be bought or sold in stock exchanges such as the New York Stock Exchange. On each day of trading, data such as the following are recorded for each stock:
* Open
* Close
* High
* Low
* Volume

The Data analysis program uses the C++ programming language to develop a program which analyze the data and provide accurate feedback to the user for the month of February 2021.

--- 

## Description
The program provide a menu with the following options:
1. Find the highest closing price of a given stock and the date on which it occurred
2. Find the total volume traded of a given stock
3. Find the date of the biggest difference between high and low prices of a given stock
4. Find the stock with the biggest difference between high and low prices on a given date
5. Find the biggest changing stock price between a previous day's close and next day's open
6. Find the percentage increase/decrease of each stock based on first day / last day prices
7. Plot a graph showing the price of a given stock on each day
8. Quit

* Option 1
  * The code for this option request the stock symbol from the user. If the symbol is not found, an appropriate message is displayed. It searches the 2-D array for the highest closing price of the given stock and displays the highest closing price and the date on which the stock was traded at this price.

* Option 2
  * The code for this option request the stock symbol from the user. If the symbol is not found, an appropriate message is displayed. The code then calculate the total volume traded for the given stock on all the trading days and display this value to the user.

* Option 3
  * The code for this option request the stock symbol from the user. If the symbol is not found, an appropriate message is displayed. The code locates the date of the biggest difference between the high and low prices of the given stock and display the date, the high and low price, and the difference.

* Option 4
  * The code for this option request the date in (day, month, year) format from the user. The program check if the data is available for this date. If not, an appropriate message is displayed. The code then check all the stocks on this date to find the stock with the biggest difference between the high and low prices. The stock symbol, the high and low price, and the difference are displayed to the user.

* Option 5
  * The code for this option examine all the stocks in the 2-D array to find the biggest price difference between a previous day’s closing price and the next day’s opening price. The stock symbol, the previous day’s closing price, the next day’s opening price, and the dates of the two days are be displayed to the user.

* Option 6 
  * The code for this option examine all the stocks in the 2-D array to find out the percentage increase/decrease in the closing price of each stock. The percentage increase/decrease is based on the closing price on the first day of the month compared to the closing price on the last day of the month.

* Option 7
  * The code for this option request the stock symbol from the user. If the symbol is not found, an appropriate message is displayed. A line graph should be generated using the closing price on each trading day. The y-axis should represent the closing price (rounded to the nearest dollar) and the xaxis represent each day. The stock price is rounded to the nearest dollar amount. The y-axis go from 0 to (the highest closing price of the stock + $1.00). The graph is then displayed to the user.
  
---

## Lanaguages tools and technologies
* C++
* Data structures

---

## Project
![Screenshot (632)](https://user-images.githubusercontent.com/77646306/124196105-bbc47d00-da99-11eb-8d7a-b5067a8452de.png)

---

## Acknowledgement

COMP1602 - Assignment

---

## Author Info
* [Linkedin](https://www.linkedin.com/in/tamika-ramkissoon-1a2622214/)
