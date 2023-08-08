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
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

`bind()` fonksiyonu, bir soketi belirli bir adres ve port numarasına bağlamak için kullanılır.

- `sockfd`: Dinlemek istediğiniz soketin tanımlayıcısı (soket fd).

- `addr`: Bu parametre, IPv4 için struct sockaddr_in veya IPv6 için struct sockaddr_in6 yapılarından birini işaret edebilir.

- `addrlen`: addr yapısının boyutunu belirten bir socklen_t türünde bir değer.


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

`accept()` fonksiyonu, yeni bir client bağlantısını kabul etmek için kullanılır. Bağlantıyı oluşturan clientın soket dosya tanımlayıcısını (clientSocket) döndürür.

- `sockfd`: Dinlemek istediğiniz soketin tanımlayıcısı (soket fd).

- `addr`: Yeni bağlantının adres bilgilerini tutar. Bağlantıyı sağlayan clientın IP adresi ve port numarası gibi bilgileri almak için kullanılır. Bu parametreyi NULL olarak belirtebilirsiniz.

- `addrlen`: addr boyutunu tutar. Bu parametreyi NULL olarak belirtebilirsiniz.


<br />


```cpp
#include <netinet/in.h>

struct sockaddr_in {
	short			sin_family;   // AF_INET
	unsigned short   sin_port;	 // htons(3490)
	struct in_addr   sin_addr;	 // see struct in_addr, below
	char			 sin_zero[8];  // zero this if you want to
};

struct in_addr {
	unsigned long s_addr;  // load with inet_aton()
};
```


- `struct sockaddr_in`: Bu struct yapısı bir server soketi oluştururken veya bir client soketine bağlanırken kullanılan adres bilgilerini içerir. Aşağıdaki struct yapısının üyeleri de ağ adres bilgilerini temsil ederler.

- `sin_family`: Adres ailesini belirtir. `AF_INET` kullanarak IPv4 adres ailesini belirtmiş olur.

- `sin_addr`: IP adresini tutar. IP adresi ise `in_addr_t` türündeki `s_addr` ile temsil edilir.

- `sin_port`: Port numarasını tutar. Port numarası, ağ byte sırasına dönüştürülmeden saklanır.

		:exclamation: Ağ byte sırasına dönüştürmek, bellekte çok byte'lık veri türleri (örneğin, 16 bit veya 32 bit) genellikle ardışık bellek hücrelerinde saklanır. Byte sıralama düzeni, bu bellek hücrelerinin hangi sıra ile sıralandığını belirler. Bunlar Big-endian ve Little-endian olarak 2'ye ayrılır. (Dilerseniz ayrıntılı bir şekilde araştırabilirsiniz.)
		
		Bir veri değerini ağ byte sırasına dönüştürmek, küçük endian düzeninde tutulan bir değeri büyük endian düzenine dönüştürmeyi ifade eder. Bu genellikle ağ protokollerinde veya farklı sistemler arasında veri alışverişinde kullanılan bir standartlaştırma yöntemidir. htons() (host to network short) ve htonl() (host to network long) gibi işlevler, bir veri değerini ağ byte sırasına dönüştürmek için kullanılır.

- `INADDR_ANY`: Local IP adreslerini kabul etmek için kullanılır.


<br />


```cpp
int inet_pton(int af, const char *src, void *dst);
```

`inet_pton()` fonksiyonu, IPv4 veya IPv6 adreslerini metin formatından ikili formata dönüştürmek için kullanılır. "pton", "presentation to numeric" anlamına gelir.

- `af`: Adres ailesini (AF_INET veya AF_INET6) belirten bir tam sayı. IPv4 için AF_INET kullanılırken, IPv6 için AF_INET6 kullanılır.

- `src`: Dönüştürülmek istenen IP adresini içeren bir C-style string (null-terminated string).

-`dst`: Dönüştürülmüş IP adresinin hedef bellek alanını temsil eden bir pointer.


<br />


```cpp
#include <string>

int main() {
	std::string str = "Merhaba";

	const char* cstr = str.c_str();

	// C-style karakter dizisini kullanma
	// ...

	return 0;
}
```

`c.str()` fonksiyonu, C-style (null-terminated) bir karakter dizisi olarak döndürür. Stringin içeriğini C diline ait fonksiyonlara veya C dilinde çalışan kütüphanelere aktarmak için kullanılır.


<br />


```cpp
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

`recv()` fonksiyonu, soketten veri almak için kullanılır. Client ve server tarafında veri alışverişi sağlar.


- `sockfd`: Dinlemek istediğiniz soketin tanımlayıcısı (soket fd).

- `buf`: Alınan verinin hedef bellek alanını temsil eden bir pointer.
	
- `len`: buf bellek alanının boyutu (byte cinsinden).
	
- `flags`: İsteğe bağlı. Özel bir işlem yapmak için kullanılabilir veya 0 olarak belirtilebilir.


<br />


`fctnl()` fonksiyonu, soketin fd üzerindeki dosya özelliklerini değiştirmek için kullanılır.

- `F_GETFL`: Mevcut dosya özelliklerini alır.

- `O_NONBLOCK`: Engellenmeyen modda açmak için kullanılan bir dosya açma flagidir.

		:exclamation: Proje özelinde fcntl() fonksiyonunu kullanacaksak sadece F_SETFL VE O_NONBLOCK flagleriyle kullanabiliyoruz bunlar dışında bir kullanım yasak.


<br />


```cpp
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```

`poll()` fonksiyonu, çoklu soket girişini aynı anda takip etmek ve olayları yönetmek için kullanılır. Bir dizi soketi izleyerek belirli bir olayın gerçekleşip gerçekleşmediğini kontrol eder. 

- `fds`: struct pollfd türünden bir dizi, izlenecek soketlerin ve beklenen olayların bilgisini içerir.
	
- `nfds`: fds dizisinin boyutu, izlenecek soket sayısını belirtir.
	
- `timeout`: İşlemin zaman aşımı süresini belirtir. Bu süre milisaniye cinsinden ifade edilir. Negatif değerler süresiz beklemeyi, 0 değeri anında dönüşü sağlar.


<br />


## Netcat Nedir?

Ağ iletişimi için kullanılan bir araçtır. Açılımı "networking Swiss Army knife" olarak adlandırılır. Temel olarak, TCP veya UDP üzerinden ağ bağlantıları kurmak, veri göndermek veya almak, port dinlemek gibi işlemleri gerçekleştirebilir. Netcat, hem bir server hem de bir client olarak çalışabilir. Server modunda, belirli bir portu dinleyerek gelen bağlantıları kabul eder. Client modunda ise belirli bir hedefe bağlanır. Netcat komutları da, server veya client modunu belirlemek, bağlantıları yönetmek, veri iletmek gibi çeşitli işlemleri gerçekleştirmek için kullanılır.

- `nc -l 8080` :arrow_right: 8080 portunu dinlemek için netcat'i server modunda çalıştırır.

- `nc 127.0.0.1 8080` :arrow_right: Client modunda çalıştırır.

- `nc 192.168.0.1 3030 < irc.txt` :arrow_right: Belirtilen ip adres ve portuna irc.txt dosyasının içeriğini gönderir.

- `nc -l 3030 > irc.txt` :arrow_right: 3030 portunu dinleyerek gelen veriyi irc.txt dosyasına kaydeder.


<br />


## Vector Nedir?

Dynamic Array yapısını temsil eder. Arraylere göre daha esnek ve güvenli bir yapı sağlar.

`#include <vector` olarak kullanılır.

`std::vector<T> myVector` :arrow_right: "T" vector'ün içinde depolanacak veri türünü temsil eder. Örnek:
`std::vector<int>`

Özelliklerinden biri dinamik boyuta sahip olmasıdır. Yani Vector'ün boyu otomatik olarak ayarlanır ve ihtiyaç duyuldukça büyütüp küçültüleiblir. Aynı zamanda elemanlara indeks kullanarak erişebiliriz.

`push_back` :arrow_rigth: Eleman eklemek için kullanılır.
`pop_back` :arrow_right: Eleman silmek için kullanılır.

Vector elemanlarına döngü kullanarak veya iteratorlerle erişebiliriz.


```cpp
#include <iostream>
#include <vector>

int main() {
	std::vector<int> myVector;

	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);

	for (int i = 0; i < myVector.size(); ++i) {
		std::cout << myVector[i] << " ";
	}

	return 0;
}
```


<!-- commands table -->
## KOMUTLAR


| Komut | Açıklama |
| :-----------: | :----------- |
| Join | Client'ın verilen kanala katılmak istediğini, her kanalın kendisi için verilen anahtarı kullandığını belirtir.  |
| Kick | Kullanıcının bir kanaldan zorla çıkarılmasını talep etmek için kullanılabilir.  |
| List | Her kanal hakkında bazı bilgilerle birlikte kanalların bir listesini almak için kullanılır.  |
| Nick | Client'a bir takma ad vermek veya bir öncekini değiştirmek için kullanılır.  |
| Notice | Hem kullanıcılar arasında hem de kanallara bildirim göndermek için kullanılır. "NOTICE" ve "PRIVMSG" arasındaki fark, "NOTICE" mesajına yanıt olarak otomatik yanıtların asla gönderilmemesidir.  |
| Pass | Bir "bağlantı şifresi" ayarlamak için kullanılır. Ayarlanırsa, bağlantıyı kaydetmeye yönelik herhangi bir girişimde bulunulmadan önce parola ayarlanmalıdır.  |
| Ping | Uygulama katmanında, bağlantının diğer tarafının hala bağlı olup olmadığını kontrol etmek veya bağlantı gecikmesini kontrol etmek için clientlar veya serverlar tarafından gönderilir.  |
| Pong | Serverlar arasında bağlantı kontrolü yapar. "PING" mesajı gönderildikten sonra kullanıcı client'ı server'a cevap olarak "PONG" mesajı gönderir. Bu, server ile client arasındaki bağlantının sağlıklı olduğunu gösterir ve iletişimin devam edebileceğini işaret eder.  |
| Privmsg | Kullanıcılar arasında özel mesaj göndermek ve ayrıca kanallara mesaj göndermek için kullanılır.  |
| Quit | Bir clientın serverla olan bağlantısını sonlandırmak için kullanılır. Server bunu bir "ERROR" mesajıyla yanıtlayarak ve client bağlantısını kapatarak onaylar.  |
| User | Yeni bir kullanıcının kullanıcı adını ve gerçek adını belirtmek için bir bağlantının başlangıcında kullanılır.  |



