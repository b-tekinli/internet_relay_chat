# ft_irc

IRC, internet üzerindeki metin tabanlı iletişim protokolüdür ve gerçek zamanlı iletişim sağlar. IRC kullanıcıları, doğrudan mesaj alışverişi yapabilir ve grup kanallarına katılabilir. IRC istemcileri, IRC sunucusuna bağlanarak kanallara katılır. IRC sunucuları, bir ağ oluşturmak için birbirine bağlanır.


## Soket Programlama Nedir?

Ağ tabanlı uygulamaların geliştirilmesi yani ağlar arasında iletişim kurmak için kullanılır. Client-Server mantığına dayanır.
**Client**, bir hizmete erişmek isteyen bir bilgisayar olarak düşünülebilir.
**Server**, bir hizmeti sağlayan bilgisayar olarak düşünülebilir.

Client ve server soketleri kullanarak birbirleriyle iletişim kurarlar.

Bir client ve server arasındaki iletişim şu adımlarla gerçekleşir;

1. Server soketi oluşturma: Server, belirli bir port üzerinden gelecek clientlara hizmet vereceği için bir soket oluşturur ve bir port numarası belirler.

2. Server soketini bağlama: Server soketi, belirlenen port numarasına bağlanır ve gelecek clientları dinlemeye başlar.

3. Client soketi oluşturma: Client, serverla iletişim kurmak için bir soket oluşturur.

4. Client soketini servera bağlama: Client soketi, serverın IP adresi ve port numarasıyla bağlantı kurar.

5. Client ve server arasında veri iletişimi: Client ve server, soketleri üzerinden veri alışverişi yaparlar. Client, servera istek gönderir ve server bu isteği işleyerek cevap verir.

6. Client ve serverın bağlantıyı sonlandırması: İşlem tamamlandıktan sonra, client ve server soketlerini kapatır ve bağlantıyı sonlandırır.


Soket programlama, TCP veya UDP gibi iletişim protokollerini kullanarak veri iletişimi sağlar. İkisinden de kısaca bahsetmek gerekirse TCP, güvenilir ve sıralı veri iletimini sağlarken, UDP daha hızlı ancak güvenilirlik gerektirmeyen veri iletimi için kullanılır.

Özetle, soket programlama ağ üzerinde veri paylaşımı, mesajlaşma, dosya aktarımı, uzaktan erişim gibi birçok uygulama senaryosunda kullanılır.


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


<br />


- `struct sockaddr_in`: Bu struct yapısı bir server soketi oluştururken veya bir client soketine bağlanırken kullanılan adres bilgilerini içerir. Aşağıdaki struct yapısının üyeleri de ağ adres bilgilerini temsil ederler.

- `sin_family`: Adres ailesini belirtir. `AF_INET` kullanarak IPv4 adres ailesini belirtmiş olur.

- `sin_addr`: IP adresini tutar. IP adresi ise `in_addr_t` türündeki `s_addr` ile temsil edilir.

- `sin_port`: Port numarasını tutar. Port numarası, ağ byte sırasına dönüştürülmeden saklanır.

        :exclamation: Ağ byte sırasına dönüştürmek, bellekte çok byte'lık veri türleri (örneğin, 16 bit veya 32 bit) genellikle ardışık bellek hücrelerinde saklanır. Byte sıralama düzeni, bu bellek hücrelerinin hangi sıra ile sıralandığını belirler. Bunlar Big-endian ve Little-endian olarak 2'ye ayrılır. (Dilerseniz ayrıntılı bir şekilde araştırabilirsiniz.)
        
        Bir veri değerini ağ byte sırasına dönüştürmek, küçük endian düzeninde tutulan bir değeri büyük endian düzenine dönüştürmeyi ifade eder. Bu genellikle ağ protokollerinde veya farklı sistemler arasında veri alışverişinde kullanılan bir standartlaştırma yöntemidir. htons() (host to network short) ve htonl() (host to network long) gibi işlevler, bir veri değerini ağ byte sırasına dönüştürmek için kullanılır.



