.. _cmake_details: 

CMake Details
#############

Overview
********

CMake is used to build your application together with the mJackets API. A
CMake build is done in two stages. The first stage is called
**configuration**. During configuration, the CMakeLists.txt build scripts are
executed. After configuration is finished, CMake has an internal model of the
mJackets API build, and can generate build scripts that are native to the host
platform.

CMake supports generating scripts for several build systems, but only Make has
tested to work with mJackets. After configuration, you begin the
**build** stage by executing the generated build scripts. These build scripts
can recompile the application without involving CMake following
most code changes. However, after certain changes, the configuration step must
be executed again before building. The build scripts can detect some of these
situations and reconfigure automatically, but there are cases when this must be
done manually.

mJackets uses CMake's concept of a 'target' to organize the build. A
target can be an executable, a library, or a generated file. For
application developers, the library target is the most important to
understand. All source code that goes into a mJackets build does so by
being included in a library target, even application code.

Library targets have source code, that is added through CMakeLists.txt
build scripts like this:

.. code-block:: cmake

   target_sources(app PRIVATE src/main.c)

In the above :file:`CMakeLists.txt`, an existing library target named ``app``
is configured to include the source file :file:`src/main.c`. The ``PRIVATE``
keyword indicates that we are modifying the internals of how the library is
being built. Using the keyword ``PUBLIC`` would modify how other
libraries that link with app are built. In this case, using ``PUBLIC``
would cause libraries that link with ``app`` to also include the
source file :file:`src/main.c`, behavior that we surely do not want. The
``PUBLIC`` keyword could however be useful when modifying the include
paths of a target library.

Application CMakeLists.txt
**************************

Every application must have a :file:`CMakeLists.txt` file. This file is the
entry point, or top level, of the build system. The final :file:`mJackets.elf`
image contains the application and API libraries.

This section describes some of what you can do in your top-level :file:`CMakeLists.txt`.
file. Make sure to follow these steps in order.

#. Add the model of your STM32 chip by setting the :makevar:`CHIP` variable. This
will allow CMake to configure your project for your specific chip by including
the appropriate drivers, and generate the approriate linker script and startup
files.

   .. code-block:: cmake

      set(CHIP STM32F405RG)

   Refer to :ref:`supported chips` for a complete list of supported chips.

   The mJackets build system determines a value for :makevar:`CHIP` by checking
   the following, in order (when a BOARD value is found, CMake stops looking
   further down the list):

   - Any previously used value as determined by the CMake cache takes highest
     precedence. This ensures you don't try to run a build with a different
     :makevar:`CHIP` value than you set during the build configuration step.

   - Any value given on the CMake command line (directly or indirectly via
     ``cmake build``) using ``-DCHIP=YOUR_CHIP`` will be checked for and
     used next.

   - If an :ref:`environment variable <env_vars>` ``CHIP`` is set, its value
     will then be used.

   - Finally, if you set ``CHIP`` in your application :file:`CMakeLists.txt`
     as described in this step, this value will be used.

#. Now add any application source files to the 'app' target
   library, each on their own line, like so:

   .. code-block:: cmake

      target_sources(app PRIVATE src/main.c)

Below is a simple example :file:`CMakeList.txt`:

.. code-block:: cmake

   project(my_app)
   set(CHIP STM32F405RG)   

   add_executable(app src/main.c)

CMakeCache.txt
**************

CMake uses a CMakeCache.txt file as persistent key/value string
storage used to cache values between runs, including compile and build
options and paths to library dependencies. This cache file is created
when CMake is run in an empty build folder.

For more details about the CMakeCache.txt file see the official CMake
documentation `Running CMake`_ .

.. _Running CMake: http://cmake.org/runningcmake/