FROM ubuntu
MAINTAINER 746_kas
COPY 5_2e.cpp lab3/trans.cpp
RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y binutils
RUN apt-get update
RUN apt-get install -y g++
