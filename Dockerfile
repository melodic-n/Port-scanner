FROM ubuntu 

RUN  apt update && \
    apt-get install -y apache2 openssh-server && \
    service ssh start && \
    service apache2 start 

EXPOSE 22  80 

FROM ubuntu

RUN apt update && \
    apt install -y apache2 openssh-server && \
    mkdir /var/run/sshd

# Expose ports
EXPOSE 22 80

CMD bash -c "service apache2 start && service ssh start && tail -f /dev/null"
