# ft_irc

IRC, internet üzerindeki metin tabanlı iletişim protokolüdür ve gerçek zamanlı iletişim sağlar. IRC kullanıcıları, doğrudan mesaj alışverişi yapabilir ve grup kanallarına katılabilir. IRC istemcileri, IRC sunucusuna bağlanarak kanallara katılır. IRC sunucuları, bir ağ oluşturmak için birbirine bağlanır.


## Soket Programlama Nedir?

Ağ tabanlı uygulamaların geliştirilmesi yani ağlar arasında iletişim kurmak için kullanılır. Client-Server mantığına dayanır.
**Client**, bir hizmete erişmek isteyen bir bilgisayar olarak düşünülebilir.
**Server**, bir hizmeti sağlayan bilgisayar olarak düşünülebilir.

Client ve server soketleri kullanarak birbirleriyle iletişim kurarlar.


<br />


## İnternet Protokolleri Nelerdir?

Ağ protokolü, 2 ya da daha fazla bilgisayar arasındaki iletişimi sağlamak amacıyla verileri düzenlemeye yarayan, standart olarak kabul edilmiş kurallar dizisidir.

**TCP**, kayıpsız veri gönderimi sağlayabilmek için kullanılan protokoldür. Gönderilen veriler için özel bir TCP kabul paketi (TCP ACK) gönderilir ve gelmiş olan paketlerin doğruluğu kontrol edilir. Gönderen taraf, kabul gelmediği sürece paketi tekrar gönderir, böylece gönderim sağlanmış olur.

**UDP**, veri gönderimini bağlantısız şekilde gerçekleştirmesidir. Ses ve video gönderiminde kullanılır. TCP'ye göre daha hızlıdır fakat güvenli değildir.


<br />


### TCP ve UDP Arasındaki Fark Nedir?
TCP bağlantı tabanlıdır, UDP bağlantı tabanlı değildir. TCP'de akış kontrolü vardır, UDP'de akış kontrolü yoktur. TCP başlığı (header) 20 bayttır, UDP başlığı 8 bayttır. TCP, UDP'den daha yavaştır, çünkü verinin karşı tarafa ulaşıp ulaşmadığını kontrol eder.


<br />


## Soketler ve Çeşitleri

4 farklı soket çeşidi vardır fakat genel olarak 2 tanesi kullanılır. Bunlar:

1. **Stream Soket (SOCK_STREAM)**: Bu tür soketler, güvenilir, veri iletimi için kullanılır. TCP üzerinden verinin doğru ve sıralı bir şekilde iletilmesini sağlarlar.

2. **Datagram Soket (SOCK_DGRAM)**: Bu tür soketler, güvenilirlik veya sıralama gerektirmeyen veri iletimi için kullanılır. UDP üzerinden çalışırlar ve bağlantısız bir iletişim modeli sağlarlar.


<br />


## Kullanılan Tüm Fonksiyonlar

```cpp

socket(AF_INET, SOCK_STREAM, 0);
```

`socket()` fonksiyonu, yeni bir soket oluşturmak için kullanılır.

İlk parametre olarak;
`AF_INET`: Bir soket oluştururken ağ protokollerini belirlemek için kullanılır. "AF" kısaltması "Address Family" yani "Adres Ailesi" anlamına gelir. AF_INET, IPv4 adres ailesini temsil eder. Bir program ***AF_INET*** kullanarak TCP/IP veya UDP gibi IPv4 tabanlı ağ protokollerini kullanarak ağ üzerinde iletişim kurabilir.
Kısaca, IPv4 kullanacağını belirtir.

İkinci parametre olarak;
`SOCK_STREAM`: TCP soketi oluşturulacağını belirtir.

Üçüncü parametre olarak;
`0`: Default protokol kullanılır.


<br />


```cpp

listen(int sockfd, int backlog);
```

`listen()` fonksiyonu, bir soketi belirli bağlantı taleplerini dinlemek için kullanılan sokete dönüştürür.

- `sockfd`: Dinlemek istediğiniz soketin tanımlayıcısı (soket fd).

- `backlog`: Gelen bağlantı taleplerinin kuyruğunda bekleyebilecek maksimum sayı. Bu, aynı anda kabul edilebilecek bağlantı sayısını belirtir.


<br /> 


```cpp

accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen); 
```

- `sockfd`: Dinlemek istediğiniz soketin tanımlayıcısı (soket fd).

- `addr`: Yeni bağlantının adres bilgilerini tutar. Bağlantıyı sağlayan clientın IP adresi ve port numarası gibi bilgileri almak için kullanılır. Bu parametreyi NULL olarak belirtebilirsiniz.

- `addrlen`: addr boyutunu tutar. Bu parametreyi NULL olarak belirtebilirsiniz.




