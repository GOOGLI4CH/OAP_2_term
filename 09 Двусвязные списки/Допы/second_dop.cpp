#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Структура, описывающая студента
struct Student {
	string surname; // Фамилия
	string name; // Имя
	string patronymic; // Отчество
	int year_of_birth; // Год рождения
	int course; // Курс
	int group_number; // Номер группы
	int grades[5]; // Оценки по пяти предметам
	Student* prev; // Указатель на предыдущий элемент списка
	Student* next; // Указатель на следующий элемент списка
};

// Функция для создания нового узла списка
Student* create_node(string surname, string name, string patronymic, int year_of_birth, int course, int group_number, int grades[]) {
	Student* node = new Student;
	node->surname = surname;
	node->name = name;
	node->patronymic = patronymic;
	node->year_of_birth = year_of_birth;
	node->course = course;
	node->group_number = group_number;
	for (int i = 0; i < 5; i++) 
	{
		node->grades[i] = grades[i];
	}
	node->prev = NULL;
	node->next = NULL;
	return node;
}

// Функция для добавления нового узла в список
void add_node(Student** head, Student** tail, Student* node) {
	if (*head == NULL) {
		*head = node;
		*tail = node;
	}
	else {
		(*tail)->next = node;
		node->prev = *tail;
		*tail = node;
	}
}

// Функция для удаления узла из списка
void remove_node(Student** head, Student** tail, Student* node) {
	if (*head == node) {
		*head = node->next;
	}
	if (*tail == node) {
		*tail = node->prev;
	}
	if (node->prev != NULL) {
		node->prev->next = node->next;
	}
	if (node->next != NULL) {
		node->next->prev = node->prev;
	}
	delete node;
}

// Функция для сортировки списка студентов по курсу и алфавиту
void merge_sort(Student** head, Student** tail) {
	if (*head == NULL || *head == *tail) {
		return;
	}
	Student* mid = *head;
	Student* temp = *head;
	while (temp != *tail && temp->next != *tail) {
		mid = mid->next;
		temp = temp->next->next;
	}
	Student* head1 = *head;
	Student* tail1 = mid;
	Student* head2 = mid->next;
	Student* tail2 = *tail;
	tail1->next = NULL;
	tail2->prev = NULL;
	merge_sort(&head1, &tail1);
	merge_sort(&head2, &tail2);
	Student* new_head = NULL;
	Student* new_tail = NULL;
	while (head1 != NULL && head2 != NULL) {
		if (head1->course < head2->course || (head1->course == head2->course && head1->surname < head2->surname)) {
			if (new_tail == NULL) {
				new_head = head1;
				new_tail = head1;
			}
			else {
				new_tail->next = head1;
				head1->prev = new_tail;
				new_tail = head1;
			}
			head1 = head1->next;
		}
		else {
			if (new_tail == NULL) {
				new_head = head2;
				new_tail = head2;
			}
			else {
				new_tail->next = head2;
				head2->prev = new_tail;
				new_tail = head2;
			}
			head2 = head2->next;
		}
	}
	if (head1 != NULL) {
		if (new_tail == NULL) {
			new_head = head1;
			new_tail = tail1;
		}
		else {
			new_tail->next = head1;
			head1->prev = new_tail;
			new_tail = tail1;
		}
	}
	if (head2 != NULL) {
		if (new_tail == NULL) {
			new_head = head2;
			new_tail = tail2;
		}
		else {
			new_tail->next = head2;
			head2->prev = new_tail;
			new_tail = tail2;
		}
	}
	*head = new_head;
	*tail = new_tail;
}

// Функция для нахождения среднего балла каждой группы по каждому предмету
void calculate_average_scores(Student* head) {
	int count[5] = { 0 };
	int total[5] = { 0 };
	while (head != NULL) {
		for (int i = 0; i < 5; i++) {
			total[i] += head->grades[i];
		}
		count[head->group_number - 1]++;
		head = head->next;
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] > 0) {
			float average_score = (float)total[i] / count[i];
			cout << "Средний балл группы " << i + 1 << " по предмету: " << average_score << endl;
		}
	}
}

// Функция для нахождения самого старшего и самого младшего студентов
void find_extreme_students(Student* head) {
	int max_year_of_birth = INT_MIN;
	int min_year_of_birth = INT_MAX;
	Student* oldest_student = NULL;
	Student* youngest_student = NULL;
	while (head != NULL) {
		if (head->year_of_birth > max_year_of_birth) {
			max_year_of_birth = head->year_of_birth;
			oldest_student = head;
		}
		if (head->year_of_birth < min_year_of_birth) {
			min_year_of_birth = head->year_of_birth;
			youngest_student = head;
		}
		head = head->next;
	}
	cout << "Самый младший студент : Фамилия: " << oldest_student->surname << ", Имя : " << oldest_student->name << ", Отчество : " << oldest_student->patronymic << ", Год рождения : " << oldest_student->year_of_birth << endl;
	cout << "Самый старший студент: " << "Фамилия: " << youngest_student->surname << ", Имя: " << youngest_student->name << ", Отчество: " << youngest_student->patronymic << ", Год рождения: " << youngest_student->year_of_birth << endl;
}

// Функция для нахождения лучшего студента каждой группы
void find_best_students(Student* head) {
	float max_average_score[5] = { 0 };
	Student* best_student[5] = { NULL };
	while (head != NULL) {
		float average_score = 0;
		int count = 0;
		for (int i = 0; i < 5; i++) {
			average_score += head->grades[i];
			count++;
		}
		average_score /= count;
		if (average_score > max_average_score[head->group_number - 1]) {
			max_average_score[head->group_number - 1] = average_score;
			best_student[head->group_number - 1] = head;
		}
		head = head->next;
	}
	for (int i = 0; i < 5; i++) 
	{
		if (best_student[i] != NULL) 
		{
			cout << "Лучший студент группы " << i + 1 << ": " << "Фамилия: " << best_student[i]->surname << ", Имя: " << best_student[i]->name << ", Отчество: " << best_student[i]->patronymic << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	// Создаем список студентов
	Student* head = NULL;
	Student* tail = NULL;
	// Заполнение списка данными о студентах
	int size = 0;
	cout << "Сколько студентов хотите добавить?" << endl;
	cin >> size;

	string surname; // Фамилия
	string name; // Имя
	string patronymic; // Отчество
	int year_of_birth; // Год рождения
	int course; // Курс
	int group_number; // Номер группы
	int grades[5]; // Оценки по пяти предметам
	
	for (int i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "Введите фамилию" << endl;
		getline(cin, surname);
		cout << "Введите имя" << endl;
		getline(cin, name);
		cout << "Введите отчество" << endl;
		getline(cin, patronymic);
		cout << "Введите год рождения" << endl;
		cin >> year_of_birth;
		cout << "Введите курс" << endl;
		cin >> course;
		cout << "Введите номер группы" << endl;
		cin >> group_number;
		cout << "Введите оценки" << endl;
		for (int j = 0; j < 5; j++)
		{
			cin >> grades[j];
		}
		Student*ptr = create_node(surname, name, patronymic, year_of_birth, course, group_number, grades);
		add_node(&head, &tail, ptr);
	}
	
	// Сортируем список по курсу и фамилии
	merge_sort(&head, &tail);
	// Находим средний балл каждой группы по каждому предмету
	calculate_average_scores(head);
	// Находим самого старшего и самого младшего студентов
	find_extreme_students(head);
	// Находим лучшего студента каждой группы
	find_best_students(head);
	// Очищаем список
	while (head != NULL) {
		Student* temp = head;
		head = head->next;
		delete temp;
	}
	return 0;
}
