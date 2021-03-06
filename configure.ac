#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.59])
AC_INIT([modlm], [0.1.0], [neubig@gmail.com])
AC_CONFIG_SRCDIR(src/modlm/modlm-train.cc)
AC_CONFIG_HEADERS([src/modlm/config.h])
AC_CONFIG_FILES([
    Makefile
    src/Makefile
    src/modlm/Makefile
    src/test/Makefile
])

AM_INIT_AUTOMAKE([-Wall subdir-objects])
AM_PROG_AR()

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_CC

AC_LANG_CPLUSPLUS

# Check for CNN
AC_ARG_WITH(dynet,
	[AC_HELP_STRING([--with-dynet=DIR], [dynet in DIR])],
	[dynet_dir="${withval}"], [dynet_dir=''])
if test "x$dynet_dir" != "x"; then
  CNN_CPPFLAGS="-I${dynet_dir}"
  CNN_LDFLAGS="-L${dynet_dir}/build/dynet -ldynet"
else
  AS_ERROR("Must specify --with-dynet=[CNN_DIR]")
fi

# Check if we have CUDA
AC_ARG_WITH(cuda,
	[AC_HELP_STRING([--with-cuda=DIR], [cuda in DIR])],
	[cuda_dir="${withval}"], [cuda_dir=''])
if test "x$cuda_dir" != "x"; then
  CNN_CPPFLAGS="-I${dynet_dir} -DHAVE_CUDA"
  CNN_LDFLAGS="-L${dynet_dir}/build/dynet -ldynet_shared -ldynetcuda -L${cuda_dir} -lcudart -lcublas"
fi
AC_SUBST(CNN_CPPFLAGS)
AC_SUBST(CNN_LDFLAGS)

# Check for Eigen
AC_ARG_WITH(eigen,
	[AC_HELP_STRING([--with-eigen=DIR], [eigen in DIR])],
	[eigen_dir="${withval}"], [eigen_dir=''])
if test "x$eigen_dir" != "x"; then
  EIGEN_CPPFLAGS="-I${eigen_dir}"
else
  AS_ERROR("Must specify --with-eigen=[EIGEN_DIR]")
fi
AC_SUBST(EIGEN_CPPFLAGS)

# Checks for libraries.
AC_SYS_LARGEFILE

# Checks for header files.
AC_CHECK_HEADERS([sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Check to make sure that we have unordered_map
AC_LANG([C++])
AC_CHECK_HEADERS([tr1/unordered_map])
AC_CHECK_HEADERS([ext/hash_map])
CXXFLAGS="$CXXFLAGS -std=c++11"

# Check if we have rt/boost
AX_BOOST_BASE([1.49], , AC_MSG_ERROR([Boost 1.49 or later is required]))
AX_BOOST_SYSTEM
AX_BOOST_PROGRAM_OPTIONS
AX_BOOST_SERIALIZATION
AX_BOOST_IOSTREAMS
AX_BOOST_UNIT_TEST_FRAMEWORK

AC_OPENMP
AC_SUBST(OPENMP_CXXFLAGS,${OPENMP_CXXFLAGS})

# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday pow sqrt])

AC_OUTPUT
