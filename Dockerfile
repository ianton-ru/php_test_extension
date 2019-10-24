FROM php:7.3.10-cli

RUN docker-php-ext-install opcache

WORKDIR test

COPY testextension.cpp testextension.cpp
COPY config.m4 config.m4
COPY test.php test.php
COPY php.ini "$PHP_INI_DIR/php.ini"

RUN phpize \
    && ./configure \
    && make \
    && make install \
    && docker-php-ext-enable testextension

ENTRYPOINT ["php", "test.php"]
