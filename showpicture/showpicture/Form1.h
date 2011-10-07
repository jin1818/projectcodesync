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
	/// Form1 摘要
	///
	/// 警告: 如果您更改该类的名称，则需要更改 
	///          与该类所依赖的所有 .resx 文件关联的托管资源编译器工具的 
	///          “资源文件名”属性。  否则，
	///          设计器将不能与此窗体关联的
	///          本地化资源正确交互。
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
		/// 必需的设计器变量。
		/// </summary>


		/// <summary>
		/// 设计器支持所需的方法 - 不要使用代码编辑器修改
		/// 此方法的内容。
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


