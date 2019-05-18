FROM ubuntu:bionic

RUN 	apt update &&  \
	apt install -y \
	build-essential \
	git wget tar \
	cmake 

WORKDIR /opt

RUN 	wget http://sourceforge.net/projects/arma/files/armadillo-9.400.3.tar.xz && \
	tar xf armadillo-9.400.3.tar.xz && \
	cd armadillo-9.400.3 && \
	mkdir build && cd build && \
	cmake .. && make && make install

WORKDIR /app

COPY . /app/armadillo-demo

CMD ["bash"]
