try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    'description': 'project skeleton',
    'author': 'peppone zuo',
    'url': 'No web page till now. Sorry, wish you could build me one.',
    'download_url': '...',
    'author_email': 'zuopengpeng@gmail.com.',
    'version': '0.1',
    'install_requires': ['nose'],
    'packages': ['peppone'],
    'scripts': [],
    'name': 'peppone'
}

setup(**config)

