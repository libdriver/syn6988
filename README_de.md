[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SYN6988

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/syn6988/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Der SYN6988-Chip ist ein High-End-Chip zur Sprachsynthese für Chinesisch und Englisch, der 2021 von Beijing Yuyin Tianxia Technology Co., Ltd. auf den Markt gebracht wurde. SYN6988 empfängt zu synthetisierende Textdaten über die UART- oder SPI-Schnittstellenkommunikation und ermöglicht so die Konvertierung von Text in Sprache (oder TTS-Sprache). Der neueste vom Unternehmen auf den Markt gebrachte SYN6988-Chip zur Sprachsynthese für Chinesisch erbt die hervorragenden Eigenschaften des High-End-Chips zur Sprachsynthese für Chinesisch SY6658: kleines Patch-Gehäuse, einfache Hardwareschnittstelle, geringer Stromverbrauch, klarer und runder Klang, nahe an der menschlichen Stimme und extrem hohe Kosteneffizienz; Darüber hinaus verfügt SYN6988 über eine englische Textanalyse und eine englische Soundbibliothek, was ihn zu einem wirklich hochwertigen, industrieorientierten Chip zur Sprachsynthese für Chinesisch und Englisch macht. Der SYN6988-Chip ist hinsichtlich Hardware und Kommunikationsschnittstellen vollständig mit dem SYN6658-Chip kompatibel.

LibDriver SYN6988 ist der voll funktionsfähige Treiber von SYN6988, der von LibDriver eingeführt wurde. Er bietet Textsynthese, Tonsynthese und andere Funktionen. LibDriver ist MISRA-kompatibel.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver SYN6988-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver SYN6988 UART, SPI.

/test enthält den Testcode des LibDriver SYN6988-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver SYN6988-Beispielcode.

/doc enthält das LibDriver SYN6988-Offlinedokument.

/Datenblatt enthält SYN6988-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige UART, SPI-Schnittstellenvorlage und stellen Sie Ihren Plattform-UART, SPI-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

#### example basic

```C
#include "driver_syn6988_basic.h"

uint8_t res;
char text[129] = "你好";

/* basic init */
res = syn6988_basic_init(SYN6988_INTERFACE_UART);
if (res != 0)
{
    return 1;
}

...
    
/* delay 500ms */
syn6988_interface_delay_ms(500);

/* syn */
res = syn6988_basic_synthesis(text);
if (res != 0)
{
    (void)syn6988_basic_deinit();

    return 1;
}
(void)syn6988_basic_sync();

...

/* sound test */
res = syn6988_synthesis_text(&gs_handle, (char const *)SYN6988_SOUND_202);
if (res != 0)
{
    (void)syn6988_deinit(&gs_handle);

    return 1;
}
(void)syn6988_basic_sync();

...
    
/* basic deinit */
(void)syn6988_basic_deinit();
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/syn6988/index.html](https://www.libdriver.com/docs/syn6988/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.