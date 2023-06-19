# ft_irc

IRC, internet üzerindeki metin tabanlı iletişim protokolüdür ve gerçek zamanlı iletişim sağlar. IRC kullanıcıları, doğrudan mesaj alışverişi yapabilir ve grup kanallarına katılabilir. IRC istemcileri, IRC sunucusuna bağlanarak kanallara katılır. IRC sunucuları, bir ağ oluşturmak için birbirine bağlanır.

Projenin amacı, C++ 98 kullanarak bir IRC sunucusu geliştirmektir. Proje, bir istemci geliştirme gerektirmez ve sunucu-sunucu iletişimini ele almanız gerekmez.

Projede istenen özellikler şunlardır:

1. Sunucunun aynı anda birden fazla istemciyi işleyebilmesi ve asla donmaması gerekmektedir.
2. Forking (çatallanma) kullanılmamalıdır. Tüm I/O işlemleri bloke etmeyen (non-blocking) olmalıdır.
3. Tüm işlemlerin (okuma, yazma, dinleme vb.) tek bir poll() (veya eşdeğer) işlevi ile yönetilmesi gerekmektedir.
4. İstemciler arasındaki iletişim TCP/IP (v4 veya v6) üzerinden gerçekleştirilmelidir.
5. Referans istemci ile sunucunuz arasındaki iletişim, resmi bir IRC sunucusu ile kullanırkenki gibi olmalıdır. Ancak, sadece aşağıdaki özellikleri uygulamanız gerekmektedir:
  - Kimlik doğrulama yapabilme, takma ad ve kullanıcı adı belirleyebilme, bir kanala katılabilme, referans istemci kullanarak özel mesajlar gönderme ve alma.
  - Bir istemciden kanala gönderilen tüm mesajlar, kanala katılan diğer tüm istemcilere iletilmelidir.
  - Operator ve normal kullanıcılar olmalıdır.
  - Ardından operatorlere özgü komutları uygulamanız gerekmektedir.

Ayrıca sunucunun doğru şekilde işlem yaptığını doğrulamak için yapılması gereken bir test örneği de içermektedir. Test, nc (netcat) kullanılarak gerçekleştirilebilir ve sunucuya gönderilen her şeyin doğru bir şekilde işlendiğini kontrol eder.
