#pragma once


namespace showpicture
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Form1 ժҪ
	///
	/// ����: ��������ĸ�������ƣ�����Ҫ���� 
	///          ����������������� .resx �ļ��������й���Դ���������ߵ� 
	///          ����Դ�ļ��������ԡ�  ����
	///          �������������˴��������
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public __gc class Form1 : public System::Windows::Forms::Form
	{	
	public:
		Form1(void)
		{
			InitializeComponent();
			
		}
  
	protected:
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::ImageList *  imageList1;
	private: System::Windows::Forms::ImageList *  imageList2;
	private: System::ComponentModel::IContainer *  components;

	private:
		/// <summary>
		/// ����������������
		/// </summary>


		/// <summary>
		/// �����֧������ķ��� - ��Ҫʹ�ô���༭���޸�
		/// �˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = new System::ComponentModel::Container();
			this->imageList1 = new System::Windows::Forms::ImageList(this->components);
			this->imageList2 = new System::Windows::Forms::ImageList(this->components);
			// 
			// imageList1
			// 
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// imageList2
			// 
			this->imageList2->ImageSize = System::Drawing::Size(16, 16);
			this->imageList2->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(6, 14);
			this->ClientSize = System::Drawing::Size(344, 358);
			this->Name = S"Form1";
			this->Text = S"Form1";

		}	
	};
}


