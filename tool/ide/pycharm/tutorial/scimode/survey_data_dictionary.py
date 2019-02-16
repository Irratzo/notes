#####################################################################
# PyCharm Scientific Mode with Code Cells
# Last Date: 181202
# Source:
# [1] https://blog.jetbrains.com/pycharm/2018/04/pycharm-scientific-mode-with-code-cells/
#####################################################################
# auxilliary file for main tutorial file python_survey.py

class ColumnDescription:
    def __init__(self, full_name=None, name='', dtype=None, converter=None, usecol=True):
        self.full_name = full_name
        if name:
            self.name = name
        else:
            self.name = full_name
        self.dtype = dtype
        self.converter = converter
        if dtype is not None and converter is not None:
            raise ValueError("Define either a dtype or a converter, not both")
        self.usecol = usecol


DATA_DICTIONARY = [
    ColumnDescription(
        full_name="Is Python the main language you use for your current projects?",
        name="python_main"
    ),
    ColumnDescription(
        full_name="None:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Java:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="JavaScript:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="C/C++:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="PHP:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="C#:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Ruby:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Bash / Shell:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Objective-C:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Go:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Visual Basic:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Scala:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="SQL:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Kotlin:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="R:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Swift:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Clojure:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Perl:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Rust:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Groovy:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="TypeScript:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="CoffeeScript:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="HTML/CSS:What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Other - Write In::What other language(s) do you use?"
    ),
    ColumnDescription(
        full_name="Educational purposes: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Data analysis: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="DevOps / System administration / Writing automation scripts: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Software testing / Writing automated tests: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Software prototyping: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Web development: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Machine learning: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Mobile development: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Desktop development: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Computer graphics: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Network programming: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Game development: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Multimedia applications development: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Embedded development: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Programming of web parsers / scrapers / crawlers: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="Other - Write In:: What do you use Python for?"
    ),
    ColumnDescription(
        full_name="What do you use Python for the most?"
    ),
    ColumnDescription(
        full_name="Which version of Python do you use the most?"
    ),
    ColumnDescription(
        full_name="Installer from python.org:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="Build from source:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="Automatic upgrade via cloud provider:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="Enthought:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="Anaconda:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="ActivePython:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="Intel Distribution for Python:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="OS-provided Python (via apt-get, yum, homebrew, etc.):What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="pyenv:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="pythonz:What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="Other - Write In::What do you typically use to upgrade your Python version?"
    ),
    ColumnDescription(
        full_name="None:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Django:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Flask:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Tornado:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Bottle:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="web2py:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="NumPy / pandas / Matplotlib / scipy and similar:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Keras / Theano / TensorFlow / scikit-learn and similar:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Pillow:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="PyQT / PyGTK / wxPython:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="TkInter:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Pygame:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="CherryPy:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Twisted:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Pyramid:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Requests:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="asyncio:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Kivy:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="six:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="aiohttp:What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Other - Write In::What framework(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="None:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Jupyter Notebook:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Anaconda:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="ORM (SQLAlchemy, PonyORM, etc.):What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Docker:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Vagrant:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Cloud platforms (Google App Engine, AWS, RackSpace, Heroku and similar):What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Hadoop, Spark, etc.:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Sphinx:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Buildout:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="DevOps tools (Ansible, Chef, Puppet, etc.):What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="redis:What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Other - Write In::What additional technology(s) do you use in addition to Python?"
    ),
    ColumnDescription(
        full_name="Google App Engine:What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="AWS:What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="Microsoft Azure:What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="RackSpace:What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="Heroku:What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="DigitalOcean:What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="Other - Write In::What cloud platform(s) do you use?"
    ),
    ColumnDescription(
        full_name="PyCharm Professional Edition:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="PyCharm Community Edition:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Sublime Text:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Vim:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Atom:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="VS Code:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Eclipse + Pydev:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Aptana:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Jupyter Notebook:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="IntelliJ IDEA:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="NotePad++:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="IDLE:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Emacs:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Python Tools for Visual Studio (PTVS):What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="NetBeans:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Spyder:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Rodeo:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Gedit:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Ninja-IDE:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Komodo Editor:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Komodo IDE:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Wing IDE:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="TextMate:What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="Other - Write In::What editor(s)/IDE(s) have you considered for use in your Python development?"
    ),
    ColumnDescription(
        full_name="What is the main editor you use for your current Python development?"
    ),
    ColumnDescription(
        full_name="use autocompletion  in your editor:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use the debugger:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="refactor your code:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use VCS:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use code linting (programs that analyze code for potential errors):When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use Python virtual environments for your projects:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use SQL databases :When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use NoSQL databases:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="run / debug or edit code on remote machines (remote hosts, VMs, etc.):When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use a Python profiler:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="write tests for your code:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use code coverage:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use optional type hinting:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use Continuous Integration tools:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="use Issue Trackers:When developing in Python, how often do you…?"
    ),
    ColumnDescription(
        full_name="Do you regularly work on multiple projects at the same time?"
    ),
    ColumnDescription(
        full_name="How did you first learn about your main editor?"
    ),
    ColumnDescription(
        full_name="How often do you use your main editor?"
    ),
    ColumnDescription(
        full_name="Are you missing any features in your main editor?"
    ),
    ColumnDescription(
        full_name="How likely is it that you would recommend your main editor to a friend or colleague?"
    ),
    ColumnDescription(
        full_name="What do you think is the ratio of these two numbers?:Please think about the total number of Python Web Developers in the world and the total number of Data Scientists using Python."
    ),
    ColumnDescription(
        full_name="What do you think would be the most popular opinion?:Please think about the total number of Python Web Developers in the world and the total number of Data Scientists using Python."
    ),
    ColumnDescription(
        full_name="Most of the time, do you...?"
    ),
    ColumnDescription(
        full_name="How many people are in your project team?"
    ),
    ColumnDescription(
        full_name="What is your employment status?"
    ),
    ColumnDescription(
        full_name="Choose one from the list::Which of the following industries best describes your company's business?"
    ),
    ColumnDescription(
        full_name="Choose one from the list::Which of the following industries do you develop for?"
    ),
    ColumnDescription(
        full_name="How long have you been working in the IT industry?"
    ),
    ColumnDescription(
        full_name="DBA:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Architect:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="QA engineer:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Developer / Programmer:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Technical support:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Data analyst:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Business analyst:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Team lead:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Product manager:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="CIO / CEO / CTO:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Systems analyst:Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Other - Write In::Which of the following best describes your job role(s)?"
    ),
    ColumnDescription(
        full_name="Could you tell us your age range?"
    ),
    ColumnDescription(
        full_name="What country do you live in?"
    ),
]
