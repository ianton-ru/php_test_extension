PHP_ARG_ENABLE(TestExtension, whether to enable Empty support, [--enable-testextension           Enable TestExtension support])
PHP_SUBST(EMPTY_SHARED_LIBADD)
PHP_REQUIRE_CXX()
PHP_NEW_EXTENSION(testextension, testextension.cpp, $ext_shared)

