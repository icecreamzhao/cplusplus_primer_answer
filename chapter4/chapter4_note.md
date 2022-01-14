# �����±ʼ�

## ��ͷ�����

ptr->item() �ȼ��� (*ptr).item()

## ������ǿ������ת��

һ��������ǿ������ת����������ʽ:

`cast-name<type>(expression)`

type ��Ŀ������, ��expression��Ҫת����ֵ��

cast-name������

* static_cast
* dynamic cast
* const_cast
* reinterpret_cast

### static_cast

�κξ�����ȷ���������ת��, ֻҪ�������ײ�const, ��������`static_cast_`

```c++
double slope = static_cast<double>i / j;
```

���ϴ����������ת��Ϊ��С����������ʱ, ʹ��static_castת�Ϳ��Թرվ�����ʧ�ľ��档

���ڱ������޷��Զ�ת��������ת��Ҳ����, �����һش����voidָ���еı�������:

```c++
void *p = &i;
int j = static_cast<int*>(p);
```

����ǿ��ת���������������, ������δ�����Ч����

### const_cast

const_castֻ�ܸı����ײ�const��

```c++
const int *ip;
int *p = const_cast<int*>(ip);
```

������ `const_cast` �ı���ʽ������, ֻ�ܸı���ʽ�ĳ�������:

```c++
const char* cpc;
char *cp = const_cast<char*>(cp);

// error
int *ip = const_cast<int*>(cp);
```

const_cast�����ں������ص��������С�

### reinterpret_cast

reinterpret_castͨ��Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½��͡�

```c++
int *ip;
chat *cp = reinterpret_cast<char*>(ip);
```

�����cpָ���ʵ������һ��int����, �����cp������ͨ���ַ�ָ��ʹ�þͿ��ܻᷢ������ʱ��������:

```c++
string str(pc);
```

> reinterpret_cast��������������, ��Ҫ��ȫ��ʹ�ñ�����漰�����ͺͱ�����ʵ��ת���Ĺ��̶��ǳ��˽�

