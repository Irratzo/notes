# ####################################################################
# # solution solution append '../..'
# ####################################################################
#
# # var1, var2: for python2+, var3: python3.6+
# import sys
# # variation1:
# sys.path.append('../..')
# # # variation2:
# # import os
# # sys.path.append(os.path.abspath('../..'))
# # # variation3:
# # from pathlib import Path
# # sys.path.append(Path('../..').resolve())
#
# from foo.bar import Foo
#
# if __name__ == '__main__':
#     foo = Foo()
#     foo.bar()

# ####################################################################
# # solution importlib
# ####################################################################
#
# # for python3.5+:
# import importlib.util
#
# spec = importlib.util.spec_from_file_location("bar", "../../foo/bar.py")
# bar = importlib.util.module_from_spec(spec)
# spec.loader.exec_module(bar)
#
# if __name__ == '__main__':
#     foo = bar.Foo()
#     foo.bar()

# ####################################################################
# # solution __file__ > os.path > append
# ####################################################################
#
# # for python2+
# import sys
# import os
#
# dir_current = os.getcwd()
# dir_file = os.path.dirname(os.path.realpath(__file__))
# os.chdir(dir_file)
# os.chdir('../..')
# dir_project = os.getcwd()
# os.chdir(dir_current)
# if dir_project not in sys.path:
#     sys.path.append(dir_project)
# from foo.bar import Foo
#
# if __name__ == '__main__':
#     foo = Foo()
#     foo.bar()

# ####################################################################
# # solution __file__ > pathlib > append
# ####################################################################
#
# # for python3.6+
# import sys
# from pathlib import Path
#
# def import_project_modules_for_script():
#     """reusable: add  project dir to sys.path when run from script.
#
#      In order to use the project folder as a module when it is not
#      installed as such, need to put it on the sys.path manually
#      before doing anything else.
#
#      Use this version if you call from an script. This version accepts calls
#      from any location, not just from the project folder. If you're calling from
#      an interpreter, use the version import_project_modules_for_interpreter instead.
#
#      This method relies on the presence of the __file__ dunder.
#
#     :return: project dir
#     :rtype: Path
#     """
#     dir_called = Path.cwd()
#     dir_script = Path(__file__).resolve().parent
#     dir_project = dir_script.parent.parent
#     if str(dir_project) not in sys.path:
#         sys.path.append(str(dir_project))
#     return dir_project
#
# import_project_modules_for_script()
# from foo.bar import Foo
#
# if __name__ == '__main__':
#     foo = Foo()
#     foo.bar()


# ####################################################################
# # solution if __file__ dunder not available
# ####################################################################
#
# # for python3.6+
# import sys
# from pathlib import Path
#
#
# def import_project_modules_for_interpreter():
#     """reusable: add  project dir to sys.path when run from interpreter.
#
#      In order to use the project folder as a module when it is not
#      installed as such, need to put it on the sys.path manually
#      before doing anything else.
#
#      Use this version if you call from an interpreter, eg a Jupyter
#      notebook. CAUTION: This version assumes that the caller was
#      executed from inside the project folder! If you're calling from
#      a script, use the version import_project_modules_for_script instead.
#
#      This version searches dirs upward until project dir found by looking
#      for a file named like '_MARKER_project_rootDir'.
#
#     :return: project dir
#     :rtype: Path
#     """
#     dir_root = Path('/')
#     dir_project = None
#     dir_called = Path.cwd()
#     dir_current = dir_called
#     FILE_TOPLEVEL_DIR_MARKER = "_MARKER_project_rootDir"
#
#     while dir_current != dir_root:
#         marker_file = dir_current / FILE_TOPLEVEL_DIR_MARKER
#         if marker_file.is_file():
#             FILE_TOPLEVEL_DIR_MARKER = marker_file
#             dir_project = dir_current
#             break
#         dir_current = dir_current.parent
#     if dir_project is None:
#         raise ImportError("Could not find project level top dir marker file "
#                           f"'{FILE_TOPLEVEL_DIR_MARKER}'. Make sure you called "
#                           "from inside the project dir and that the marker file "
#                           "is present.")
#     if str(dir_project) not in sys.path:
#         sys.path.append(str(dir_project))
#         # now can load stuff from project DFT_Tutorial.modules
#     return dir_project
#
#
# import_project_modules_for_interpreter()
# from foo.bar import Foo
#
# if __name__ == '__main__':
#     foo = Foo()
#     foo.bar()


####################################################################
# solution combined file dunder & upwards search
####################################################################

# for python3.6+
import sys
from pathlib import Path
import logging

logging.basicConfig(level=logging.DEBUG)  # DEBUG > INFO > WARN > ERROR

THIS_FILE_RELATIVE_PROJECT_PATH = "u/v/script.py"


def import_project_modules():
    """add project modules to sys.path manually to enable import for scripts/interpreters

    Requires EITHER global variable THIS_FILE_RELATIVE_PROJECT_PATH = e.g. "a/b/file.py",
    OR a file named '_MARKER_project_rootDir' ('project' is a wildcard) in order to work.

    In order to use modules from the project folder when it/they is not
    installed as package/modules, need to put it on the sys.path manually
    before being able to import them.

    This function first tries to get this file's location using __file__ dunder, then
    going upwards to the project dir and adding that to sys.path. If __file__ dunder is
    not available, eg cause called from interpreter, then tries to search upwards for a
    marker file denoting the project root, and adding that dir to sys.path.

    :return: project dir
    :rtype: Path
    """
    logger = logging.getLogger(__name__)

    try:
        dir_script = Path(__file__).resolve().parent
        depth = max(THIS_FILE_RELATIVE_PROJECT_PATH.count("/"),
                    THIS_FILE_RELATIVE_PROJECT_PATH.count("\\"))
        dir_project = dir_script
        while depth > 0:
            dir_project = dir_project.parent
            depth -= 1
        if str(dir_project) not in sys.path:
            logger.debug(f"used script version")
            sys.path.append(str(dir_project))
        return dir_project
    except (SystemExit, KeyboardInterrupt):
        raise
    except NameError as name_error:
        # NameError: name '__file__' is not defined
        # means: called from interpreter or similar
        logger.debug(f"implies called from interpreter not from script."
                     f"try upward search for project _MARKER file.", exc_info=name_error)

        dir_project = None
        dir_called = Path.cwd()
        dir_current = dir_called.resolve()
        dir_upper = dir_current.parent
        FILE_TOPLEVEL_DIR_MARKER = "_MARKER_project_rootDir"

        while dir_current != dir_upper:
            matches = list(dir_current.glob("_MARKER_*_rootDir"))
            match = matches[0] if (len(matches) > 0) else None
            if match:
                FILE_TOPLEVEL_DIR_MARKER = match
                dir_project = dir_current
                break
            dir_upper = dir_upper.parent
            dir_current = dir_current.parent
        if dir_project is None:
            raise ImportError("Could not find project level top dir marker file "
                              f"'{FILE_TOPLEVEL_DIR_MARKER}'. Make sure you called "
                              "from inside the project dir and that the marker file "
                              "is present.")
        if str(dir_project) not in sys.path:
            sys.path.append(str(dir_project))
            # now can load stuff from project DFT_Tutorial.modules
        return dir_project

    else:
        pass
    finally:
        pass


import_project_modules()
from foo.bar import Foo

if __name__ == '__main__':
    foo = Foo()
    foo.bar()
