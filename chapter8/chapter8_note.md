# �ڰ��±ʼ�

## IO ��

Ϊ��֧��ʹ�ÿ��ַ�������, ��׼�ⶨ����һ�����ͺͶ��������� wchar_t ���͵����ݡ����ַ��汾�����ͺͺ�����������һ�� w ��ʼ������: wcin��wcout �� wcerr��

### ����״̬

| ״̬ | ˵�� |
| ---: | :-- |
| strm::iostate | iostate ��һ�ֻ�����ص�����, �ṩ�˱������״̬���������� |
| strm::badbit | ����ָ�����ѱ��� |
| strm::failbit | ����ָ��һ��IO����ʧ���� |
| strm::eofbit | ����ָ�����ﵽ���ļ����� |
| strm::goodbit | ����ָ����δ���ڴ���״̬����ֵ��֤Ϊ�� |
| s.eof() | ����s��eofbit��λ, �򷵻�true |
| s.fail() | ����s�� failbit �� badbit ��λ, �򷵻� true |
| s.bad() | ����s�� badbit ��λ, �򷵻� true |
| s.good() | ����s������Ч״̬, �򷵻� true |
| s.clear() | ����s����������״̬λ��λ, ������״̬����Ϊ��Ч, ���� void |
| s.clear(flags) | ���ݸ����� flags ��־λ, ����s�ж�Ӧ������״̬λ��λ��flags������Ϊstrm::iostate������void |
| s.setState(flags) | ���ݸ����� flags ��־λ, ����s�ж�Ӧ����״̬λ��λ��flags������Ϊstrm::iostate������void |
| s.rdstate() | ������s�ĵ�ǰ����״̬, ����ֵ����Ϊ strm::iostate |

### ��ѯ����״̬

IO�ⶨ�����ĸ�iostate���͵�constexprֵ, ������ʾ����ǰ��״̬��

* badbit ��ʾϵͳ������, һ��badbit����λ, �����޷���ʹ���ˡ�
* failbit ��ʾ�ɻָ�����, �絽���ļ�����λ��, eofbit��failbit���ᱻ��λ
* goodbit ��ʾ��δ��������

����goodbit֮��, ��������һ��״̬����λ, �������(if ���� while) ����ʧ�ܡ�

### �����������

����ʹ�������ַ���ˢ�»�����:

* flush ֱ�����, �������κ��ַ�
* ends ����һ���ո��ַ���ˢ��
* endl ����һ�����з���ˢ��

unitbuf �ַ�

```c++
// ���������е�����������һ��flush����
cout << unitbuf;
// �ص�
cout << nounitbuf;
```

> waring ����������, �����������Զ�ˢ��

### �����������������

��һ�������������������ʱ, �κ���ͼ����������ȡ�Ĳ��������ȹ����������

`cin >> inval` �ᵼ��cout��ˢ��

```c++
cin.tie(&cout);
// ���cin�Ĺ���
ostream *old_tie = cin.tie(nullptr);
```
## �ļ��������

������cout, cin�Ĳ���Ҳ��������ifstream��ofstream��, ��Ϊifstream��ofstream�̳���stream���͡�

fstream���еĲ���:

| ���� | ˵�� |
| --: | :--- |
| fstream fstrm | ����һ��δ�󶨵��ļ���, fstream��ͷ�ļ�fstream�����һ������ |
| fstream fstrm(s) | ����һ��fstream, ������Ϊs���ļ�, s������string����, ������һ��ָ��C����ַ�����ָ��, ��Щ���캯������explicit��, Ĭ�ϵ��ļ�ģʽmode������fstream������ |
| fstream fstrm(s, mode); | ��ǰһ�����캯������, ����ָ��mode���ļ� |
| fstrm.open(s) | ����Ϊs���ļ�, �����ļ���fstrm�󶨡�s������һ��string��һ��ָ��C����ַ�����ָ�롣Ĭ�ϵ��ļ�mode ������fstream����, ����void |
| fstrm.close() | �ر���fstrm�󶨵��ļ�, ����void |
| fstrm.is_open() | ����һ��boolֵ, ָ����fstrm�������ļ��Ƿ�ɹ��򿪲�����δ�ر� |

### ��Ա����open��close

�������һ�����ļ�������, ���Ե���open���������ļ���������:

```c++
// ֱ��ʹ��ifile��ʼ���ļ���
ifstream in(ifile);

// ����ļ���δ���κ��ļ������
ofstream out;
out.open(ifile + "copy");

if (out)
    // file open success

in.close(); // �ر��ļ�
```

��һ��fstream��������ʱ, ���Զ�����close()������

## �ļ�ģʽ

| �ļ�ģʽ | ˵�� |
| ------: | :--- |
| in | �Զ���ʽ�� |
| out | ��д��ʽ�� |
| app | ÿ��д����ǰ����λ���ļ�ĩβ |
| ate | ���ļ���������λ���ļ�ĩβ |
| trunc | �ض��ļ� |
| binary | �Զ����Ʒ�ʽ����IO |

ָ���ļ�ģʽʱ����������:

* ֻ���Զ�ofstream��fstream����outģʽ
* ֻ���Զ�ifstream��fstream����inģʽ
* ֻ�е�outҲ���趨ʱ�ſ�������truncģʽ
* ֻҪtruncģʽû�б��趨, �Ϳ�������appģʽ����appģʽ��, ��ʹû���趨outģʽ, �ļ�Ҳ�����������ʽ��
* Ĭ�������, ��ʹû��ָ��truncģʽ, ��outģʽ�򿪵��ļ�Ҳ�ᱻ�ض�, Ϊ�˱�����outģʽ�򿪵��ļ�������, ����ͬʱָ��appģʽ, ����ֻ�Ὣ����׷�����ļ�ĩβ; ����ͬʱָ��inģʽ, ���ļ���ͬʱ���ж�д����
* ate��binary�������κ����͵��ļ�������, �ҿ������κ��ļ�ģʽ���ʹ��

δָ���ļ�ģʽʱ, ifstream�������ļ�Ĭ����inģʽ��, ofstreamĬ����outģʽ��, fstreamĬ����out��inģʽ�򿪡�

��outģʽ���ļ��ᶪ����������, �˴����Բ鿴`Chapter_8.h`�е�overwrite_file()������

����open�������ļ�����ʽ��ʼ���ķ�ʽ������ָ���ļ�ģʽ:

```c++
ifstream ifs("test.txt", ifstream::app);
ifstream ifs;
ifs.open("test.txt", ifstream::app);
```

## string ��

stringstream ���еĲ���:

| ���� | ˵�� |
| ---: | :-- |
| sstream strm; | strm ��һ��δ�󶨵�stringstream����, sstream ��ͷ�ļ�sstream��һ������ |
| sstream strm(s) | strm ��һ��sstream����, ���� string s ��һ������, �˹��캯���� explicit �� |
| strm.str() | ����strm�������string�Ŀ��� |
| strm.str(s) | ��string s������strm��, ����void |

istringstream �� ostringstream

