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