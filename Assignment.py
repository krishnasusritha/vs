"""
Krishna Susritha Mylavarapu
August 15th 2024
Description: This program is to write unit tesr cases for Stock class.
"""
import json
import pandas as pd
import yfinance as yf
from datetime import datetime
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from matplotlib.dates import DateFormatter
import datetime as dt

# Read the CSV file
data = pd.read_csv(r'C:\Users\vineeth\Desktop\Krishna Susritha\DU\ICT-4370\Week-8\Lesson6_Data_Stocks.csv')
df = pd.DataFrame(data, columns=['SYMBOL', 'NO_SHARES'])

# Read the JSON file
file_path = r'C:\Users\vineeth\Desktop\Krishna Susritha\DU\ICT-4370\Week-8\AllStocks.json'
with open(file_path) as file:
    stocks_data = json.load(file)

# Define the Shares class
class Shares:
    def __init__(self, no_shares, stock_name):
        self.no_shares = no_shares
        self.stock_name = stock_name

# Define the Stock class
class Stock:
    def __init__(self, symbol, date, open_price, high, low, close, volume):
        self.symbol = symbol
        self.date = date
        self.open = open_price
        self.high = high
        self.low = low
        self.close = close
        self.volume = volume

    def add_new_stock(self, closing_price):
        self.closing_price = closing_price

    def calculate_closing_price(self, no_shares):
        closing_price = round(float(self.close) * int(no_shares), 2)
        return closing_price

# Fetching more recent stock prices using Yahoo Finance API
def fetch_recent_prices(symbol):
    try:
        stock_data = yf.Ticker(symbol)
        hist = stock_data.history(period="5y") # Last 5 years
        if hist.empty:
            print(f"{symbol}: No data found, symbol may be delisted")
            return None
        return hist['Close'].to_dict()
    except Exception as e:
        print(f"Error fetching data for {symbol}: {e}")
        return None

# Create a list of Stock objects from JSON data
stock_objects = []
for stock in stocks_data:
    try:
        stock_obj = Stock(stock['Symbol'], stock['Date'], stock['Open'], stock['High'], stock['Low'], stock['Close'], stock['Volume'])
        stock_objects.append(stock_obj)
    except KeyError as e:
        print(f"Missing data in JSON for key: {e}")

# Create a dictionary to store plot data
plot_data = {}
for stock in stock_objects:
    symbol_df = df.loc[df['SYMBOL'] == stock.symbol]
    if not symbol_df.empty:
        no_shares = symbol_df['NO_SHARES'].iloc[0]
        closing_price = stock.calculate_closing_price(no_shares)
        stock.add_new_stock(closing_price)
        if stock.symbol.upper() not in plot_data:
            plot_data[stock.symbol.upper()] = []
        plot_data[stock.symbol.upper()].append([datetime.strptime(stock.date, '%d-%b-%y'), stock.closing_price])

# Mapping of old symbols to new symbols
symbol_mapping = {
 'RDS-A': 'SHEL', # Shell (RDS-A) changed to SHEL
 'FB': 'META' # Facebook (FB) changed to Meta Platforms (META)
}
for symbol in df['SYMBOL']:
    current_symbol = symbol_mapping.get(symbol, symbol)  # Map to new symbol if exists
    recent_prices = fetch_recent_prices(current_symbol)
    if recent_prices is not None:
        if current_symbol.upper() not in plot_data:
            plot_data[current_symbol.upper()] = []
        for date, price in recent_prices.items():
            plot_data[current_symbol.upper()].append([date, price])

# Plotting the graph
fig, ax = plt.subplots(figsize=(10, 6))
ax.xaxis.set_major_locator(mdates.MonthLocator(interval=3)) # Every 3 months
ax.xaxis.set_major_formatter(DateFormatter("%Y-%m"))
ax.xaxis.set_tick_params(rotation=45)
left = dt.date(2015, 11, 9)
right = dt.date(2023, 11, 10) # Extended to more recent data
plt.gca().set_xbound(left, right)
for symbol, data in plot_data.items():
    xAxis = [value[0] for value in data]
    yAxis = [value[1] for value in data]
    ax.plot(xAxis, yAxis, label=symbol)
plt.xlabel('Date')
plt.ylabel('Closing Price')
ax.legend()
plt.tight_layout()
plt.savefig('week_10.png')
plt.show()
