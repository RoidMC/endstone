__all__ = ["Plugin"]

from endstone._api import Plugin as _Plugin


class Plugin(_Plugin):
    def __init__(self):
        _Plugin.__init__(self)

    @property
    def __description__(self):
        # TODO: pass description from python back to c++, should not be called by end users
        raise NotImplementedError