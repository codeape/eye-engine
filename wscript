from waflib.Configure import conf

APPNAME = 'engine'
VERSION = '0.0.1'
BUG_ADDRESS = "Do not know"

def options(opt):
    opt.load('compiler_cxx')

@conf
def libckok (ctx, libname, libpath):
    ctx.check(header_name=libpath, features='c cprogram',
              okmsg="{0} is present".format(libname),
              errmsg="{0} is not present".format(libname))

@conf
def standard_defs(ctx):
    ctx.define('ORC_VERSION', VERSION)
    ctx.define('ORC_BUG_ADDRESS', BUG_ADDRESS)
    ctx.define('DEST_OS', ctx.env.DEST_OS.upper())

def configure(ctx):
    ctx.load('compiler_cxx')
    ctx.recurse('engine')
    ctx.recurse('sample')

def build(ctx):
    ctx.recurse('engine')
    ctx.recurse('sample')
