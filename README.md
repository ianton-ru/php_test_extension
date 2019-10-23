# php_test_extension
php test extension to reproduce bug

build:
```
phpize && ./configure && make && make install
```

add to php.ini:
```
extension=testextension.so
```

or for docker:
```
docker-php-ext-enable testextension
```

## Test
OpCache corrupts class static method result in custom extension when method name matches with some php function.
Without OpCache or with unique method name all works fine.

```
php test.php
```

Expected result:
```
Test
```

Actual result with OpCache:
```
NULL
```
