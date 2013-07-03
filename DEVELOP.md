
Code standard
=============

This code standard is heavily inspired by the one used for id thech 4 engine.

General
-------

Use 4 space character indentation.

Use typically trailing braces everywhere (if, else, functions, structures,
typedefs, class definitions, etc.)

    if ( x ) {
    }

The else statement starts on the same line as the last closing brace.

    if ( x ) {
    } else {
    }

Pad parenthesized expressions with spaces

    if ( x ) {
    }

Instead of

    if (x) {
    }

And

    x = ( y * 0.5f );

Instead of

    x = (y * 0.5f);

Use precision specification for floating point values unless there is an
explicit need for a double.

    float f = 0.5f;

Instead of

    float f = 0.5;

And

    float f = 1.0f;

Instead of

    float f = 1.f;


Function names start with an lower case:

    void function( void );


In multi-word function names each word starts with an upper case:

    void thisFunctionDoesSomething( void );


The standard header for functions is:

    /*
    ====================
    functionName

      Description
    ====================
    */

Variable names start with a lower case character.

    float x;


In multi-word variable names the first word starts with a lower case character
and each successive word starts with an upper case.

    float maxDistanceFromPlane;

Typedef names use the same naming convention as variables, however they always
end with "_t".

    typedef int fileHandle_t;

Struct names use the same naming convention as variables, however they always
end with "_t".

    struct renderEntity_t;

Enum names use the same naming convention as variables, however they always end
with  "_t". The enum constants use all upper case characters. Multiple words are
separated with an underscore.

    enum contact_t {
        CONTACT_NONE,
        CONTACT_EDGE,
        CONTACT_MODELVERTEX,
        CONTACT_TRMVERTEX
    };

Names of recursive functions end with "_r"

    void walkBSP_r( int node );

Defined names use all upper case characters. Multiple words are separated with
an underscore.

    #define SIDE_FRONT      0

Use ‘const’ as much as possible.

Use:

    const int *p;           // pointer to const int
    int * const p;          // const pointer to int
    const int * const p;    // const pointer to const int

Don’t use:

    int const *p;

Classes
-------

The standard header for a class is:

    /*
    ============================================================================

        Description

    ============================================================================
    */

Class names start with "Eng" and each successive word starts with an upper case.

    class EngVec3;

Class variables have the same naming convention as variables.

    class EngVec3 {
        float       x;
        float       y;
        float       z;
    }

Class methods have the same naming convention as functions.

    class EngVec3 {
        float       length( void ) const;
    }

Indent the names of class variables and class methods to make nice columns. The
variable type or method return type is in the first column and the variable name
or method name is in the second column.

    class EngVec3 {
        float           x;
        float           y;
        float           z;
        float           length( void ) const;
        const float *   toFloatPtr( void ) const;
    }

The * of the pointer is in the first column because it improves readability when
considered part of the type.

Ordering of class variables and methods should be as follows:

    1. list of friend classes
    2. public variables
    3. public methods
    4. protected variables
    5. protected methods
    6. private variables
    7. private methods

This allows the public interface to be easily found at the beginning of the
class.

Always make class methods ‘const’ when they do not modify any class variables.

Avoid use of ‘const_cast’.  When object is needed to be modified, but only const
versions are accessible, create a function that clearly gives an editable
version of the object.  This keeps the control of the ‘const-ness’ in the hands
of the object and not the user.

Return ‘const’ objects unless the general usage of the object is to change its
state.

Function overloading should be avoided in most cases.  For example, instead of:

    const EngAnim *  getAnim( int index ) const;
    const EngAnim *  getAnim( const char *name ) const;
    const EngAnim *  getAnim( float randomDiversity ) const;

Use:

    const EngAnim *  getAnimByIndex( int index ) const;
    const EngAnim *  getAnimByName( const char *name ) const;
    const EngAnim *  getRandomAnim( float randomDiversity ) const;

Explicitly named functions tend to be less prone to programmer error and
inadvertent calls to functions due to wrong data types being passed in as
arguments.  Example:

    Anim = getAnim( 0 );

This could be meant as a call to get a random animation, but the compiler would
interpret it as a call to get one by index.

Overloading functions for the sake of adding ‘const’ accessible function is
allowable:

    class EngAnimatedEntity : public EngEntity {
        idAnimator *        getAnimator( void );
        const idAnimator *  getAnimator( void ) const;
    };

In this case, a const version of getAnimator was provided in order to allow
getAnimator to be called from const functions.  Since EngAnimatedEntity is
normally a non-const object, this is allowable.  For a media type, which is
normally const, operator overloading should be avoided:

    class EngDeclMD5 : public EngDecl {
        const EngMD5Anim *   getAnim( animHandle_t handle ) const;
        EngMD5Anim *         getEditableAnim( animHandle_t handle );
    };

File names
----------

Each class should be in a seperate source file unless it makes sense to group
several smaller classes. The file name should be the same as the name of the
class. (Upper/lower case is preserved.)

    class EngWinding;
    files:
    EngWinding.cpp
    EngWinding.h

When a class spans across multiple files these files have a name that starts
with the name of the class without "id", followed by an underscore and a
subsection name.

    class EngRenderWorld;
    files:
    EngRenderWorld_load.cpp
    EngRenderWorld_demo.cpp
    EngRenderWorld_portals.cpp
