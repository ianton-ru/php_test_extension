#include <php.h>                                                                      
#include <php_ini.h>                                                                  
#include <Zend/zend_exceptions.h>                                                     
#include <Zend/zend_types.h>                                                          

// change it on some unique name, 'serialize2' for example
#define FNAME serialize                                                             

ZEND_MINIT_FUNCTION(TestExtension);
ZEND_METHOD(TestExtension, FNAME);

static zend_function_entry functions[] = {
	{ NULL, NULL, NULL }
};

zend_module_entry TestExtension_module_entry = {
	STANDARD_MODULE_HEADER,
	"TestExtension",
	NULL,
	ZEND_MINIT(TestExtension),
	NULL,
	NULL,
	NULL,
	NULL,
	"Test",
	STANDARD_MODULE_PROPERTIES
};

#pragma GCC visibility push(default)                                                  
extern "C" {
	ZEND_GET_MODULE(TestExtension)
}
#pragma GCC visibility pop                                                            

zend_class_entry *dalClassEntry;

static zend_function_entry dalClassFunctions[] = {
	ZEND_ME(TestExtension, FNAME, NULL, ZEND_ACC_STATIC | ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

ZEND_MINIT_FUNCTION(TestExtension)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "TestExtension", dalClassFunctions);
	dalClassEntry = zend_register_internal_class(&ce TSRMLS_CC);
	return SUCCESS;
}

ZEND_METHOD(TestExtension, FNAME)
{
	array_init(return_value);
	add_next_index_string(return_value, "Test");
}

