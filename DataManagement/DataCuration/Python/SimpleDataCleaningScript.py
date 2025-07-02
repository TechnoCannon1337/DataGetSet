import pandas as pd

def clean_data(filepath):
    """
    Loads a CSV file, cleans missing values, and removes duplicates.
    """
    df = pd.read_csv(filepath)

    # Handle missing values: fill numerical NaNs with mean, string NaNs with 'Unknown'
    for col in df.columns:
        if df[col].dtype in ['int64', 'float64']:
            df[col] = df[col].fillna(df[col].mean())
        elif df[col].dtype == 'object':
            df[col] = df[col].fillna('Unknown')

    # Remove duplicate rows
    df = df.drop_duplicates()

    return df

# Usage example
# cleaned_dataframe = clean_data('raw_data.csv')
# cleaned_dataframe.to_csv('cleaned_data.csv', index=False)
