#include "reflect.h"

int main(int argc, char** argv)
{
	Object* obj = new Json();

	vector<ReflectItem> vec = ReflectHelper::GetList(obj->getClassName());

	puts(" 类成员变量定义");
	puts("------------------------------------------------------");
	for (auto& item : vec)
	{
		cout << " " << item.getType() << " " << item.getName() << ";" << endl;
	}

	//设置成员变量的值
	ReflectHelper::GetItem("Json", "intval").set(obj, 100);
	ReflectHelper::GetItem("Json", "boolval").set(obj, true);
	ReflectHelper::GetItem("Json", "stringval").set(obj, "xungen");

	puts("");
	puts(" 成员变量的值");
	puts("------------------------------------------------------");
	for (auto& item : vec)
	{
		cout << " " << item.getName() << " = " << item.get(obj) << ";" << endl;
	}

	puts("");
	puts(" 序列化为JSON串");
	puts("------------------------------------------------------");
	cout << " " << obj->toString() << endl;

	delete obj;

	return 0;
}
