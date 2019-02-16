#####################################################################
# PyCharm Scientific Mode with Code Cells
# Last Date: 181202
# Source:
# [1] https://blog.jetbrains.com/pycharm/2018/04/pycharm-scientific-mode-with-code-cells/
#####################################################################

import pandas as pd

from survey_data_dictionary import DATA_DICTIONARY
names = [x.name for x in DATA_DICTIONARY]
# Generate the list of names to import
usecols = [x.name for x in DATA_DICTIONARY if x.usecol]
# dtypes should be a dict of 'col_name' : dtype
dtypes = {x.name: x.dtype for x in DATA_DICTIONARY if x.dtype}
# name for convertes
converters = {x.name : x.converter for x in DATA_DICTIONARY if x.converter}


df = pd.read_csv('data/pythondevsurvey2017_raw_data.csv',
                 header=0,
                 names=names,
                 dtype=dtypes,
                 converters=converters,
                 usecols=usecols)

# Stopped doing/continuirng with tutorial here.
# Resume at leisure, see link.

#%% run > bottom screen Python console > df > view as dataframe


