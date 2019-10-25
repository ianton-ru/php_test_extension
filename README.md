# php_test_extension
php test extension to reproduce [bug 78747](https://bugs.php.net/bug.php?id=78747)

**FIXED**

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
php -c php.ini test.php
```
or
```
docker build . -t php_test_extension
docker run php_test_extension
```

Expected result:
```
Test
```

Actual result with OpCache:
```
NULL
```
