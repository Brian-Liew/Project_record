# Android开发最全入门

## 一、工程项目结构解析：

对于一般的文件结构，我们最熟悉的就是：

![main](F:\markdown\main.jpg)

通过这个文件架构我们可以看到一般的工程被囊括在src的文件夹中，我们所写的开发文件一般都是在main文件夹中的java文件夹中，而res文件夹则是存放了我们在开发中用到的包括图片、架构、菜单等等各种资源的文件。

##### 下面对res文件夹中的文件做一个说明：

例如在图片资源中：

> - **drawable：**存放各种位图文件，(.png，.jpg，.9png，.gif等)除此之外可能是一些其他的drawable类型的XML文件
> - **mipmap-hdpi：**高分辨率，一般我们把图片丢这里
> - **mipmap-mdpi：**中等分辨率，很少，除非兼容的的手机很旧
> - **mipmap-xhdpi：**超高分辨率，手机屏幕材质越来越好，以后估计会慢慢往这里过渡
> - **mipmap-xxhdpi：**超超高分辨率，这个在高端机上有所体现

在布局资源上：layout就是我们最常使用的视图框架，我们根据屏幕匹配，创建一套自己想要的视图，也就是我们每一次大一一个APP所看到的那个画面。

在菜单资源上：简单地理解就是我们应用上的菜单键；

接下来是values目录：

> - demens.xml：定义尺寸资源
> - string.xml：定义字符串资源
> - styles.xml：定义样式资源
> - colors.xml：定义颜色资源
> - arrays.xml：定义数组资源
> - attrs.xml：自定义控件时用的较多，自定义控件的属性！
> - theme主题文件，和styles很相似，但是会对整个应用中的Actvitiy或指定Activity起作用，一般是改变窗口外观的！可在Java代码中通过setTheme使用，或者在Androidmanifest.xml中为<application...>添加theme的属性！ PS:你可能看到过这样的values目录：values-w820dp，values-v11等，前者w代表平板设备，820dp代表屏幕宽度；而v11这样代表在API(11)，即android 3.0后才会用到的！

当然还有很多，例如raw存放着原生资源（音频、视频等等），可以通过特定函数获得资源的二进制流；还有动画：包括属性动画、补间动画。

##### 怎么去使用这些资源：

分为在java代码以及在xml代码中：

在java中：用R.string.name等等的语句

在xml代码中用：@string/hello_world

#### 怎么去理解不同后缀名字的文件：

##### 对于java文件：

最简单的就是通过它来创建一个活动，例如mainactivity：

```java
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
```

这样的代码以后在我们的讲解中是最常见的，我们首先定义了一个活动类，然后去实现它被创建之后的onCreate（）的方法，这个方法调用了父类的onCreate（）的方法，然后进行界面的设置，设置成activity_main这个布局。所以我们就要来看一下这个布局怎么样：

##### 对于xml布局文件：

```java
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="@string/hello_world" />

</RelativeLayout>
```

这样的一个布局就是最普通的布局了，我们设置它为相对布局，在布局里面添加一个文本显示。

##### 对于AndroidMainfest.xml配置文件：

```java
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="jay.com.example.firstapp" >

    <application
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:theme="@style/AppTheme" >
        <activity
            android:name=".MainActivity"
            android:label="@string/app_name" >
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>

</manifest>
```

对于这样一个代码我们可以参考下面的解释：

![main2](F:\markdown\main2.jpg)

总结一下，到这一步你基本就把我们后续会看到的所有文件架构给看清楚了，就是这么简单，活动的编写java代码，布局的代码以及配置代码，当然我们重点是在开发java，代码，其他都是很简单就可以实现的。



## 二、UI界面的设计

对于安卓开发我们的第一印象肯定就是APP的界面，这些界面的设计都是从布局、资源这些开始的，我们接下来就来看看它的UI布局吧：

我们熟悉的界面布局有哪些呢？可能让你说出名字很难，但是你还是会有自己的一点印象吧，例如给你说一个线性布局，相对布局、表格布局、网格布局你也大概能够猜出这是一个什么样的，我们首先就说一个线性布局：

#### 线性布局：

![linearlaout](F:\markdown\linearlaout.jpg)

总的来说线性布局的属性就是这些，包括我们的视图套件需要怎么样去放的排列方式，还有它们的参考基平面等等。

需要注意的就是我们对于布局权重的设置，如果整体的布局是wrap_content，那么我们只需要根据总的权重和去分配比例，如果是match_parent的话，就需要进行计算了，首先算出整体的权重分配比例，用1减去2*各自的分配比例就ok了。

如果要设置一条分界线可以用View进行设置，通过高度的设置可以调节线的宽度；或者使用diveider进行设置。

#### 相对布局：

![relativelayout](F:\markdown\relativelayout.png)

需要区分的就是margin和padding的关系，都是间隔一段距离，但是margin是偏移一段距离，而padding是填充那段距离，如果有颜色，padding会填充那一段距离。

#### 表格布局：

表格布局就是按表格进行分配空间，最主要的特色就是可以隐藏、拉伸等等操作：collapseColumn可以隐藏列，strechColumns可以拉伸列，shrink可以收缩列。

#### 帧布局：

帧布局的属性很少就只有两个，一个设置前景图像，另一个设置前景图像显示的位置，例如我们想要弄一个可以移动图像的APP，那么我们可以首先重定义一个view类，提供它的坐标以及画图函数，然后在主活动中，根据触摸事件判断位置进行重绘图。

#### 网格布局：

用于计算器的布局设计，脑补一下你就理解了，主要能够设计行数和列数。

#### 绝对布局：

就是你设计死了它的长宽，容易理解吧，相对和绝对嘛。

接下来就是我们具体一点的组件了，那么我们可以简单的带过，因为这些组件都是大同小异：

#### 组件：

##### TextView、EditView、Button、ImageView、CheckBox、ProgressBar、SeekBar、ListView等等

#### 菜单：

菜单分为选项菜单、上下文菜单、子菜单以及弹出式菜单。比较常用的是选项菜单，我们一般通过以下示例实现：

> ```java
> public class MainActivity extends AppCompatActivity {
> 
>     //1.定义不同颜色的菜单项的标识:
>     final private int RED = 110;
>     final private int GREEN = 111;
>     final private int BLUE = 112;
>     final private int YELLOW = 113;
>     final private int GRAY= 114;
>     final private int CYAN= 115;
>     final private int BLACK= 116;
> 
>     private TextView tv_test;
> 
>     @Override
>     protected void onCreate(Bundle savedInstanceState) {
>         super.onCreate(savedInstanceState);
>         setContentView(R.layout.activity_main);
>         tv_test = (TextView) findViewById(R.id.tv_test);
>     }
> 
>     @Override
>     public boolean onCreateOptionsMenu(Menu menu) {
>         // Inflate the menu; this adds items to the action bar if it is present.
>         menu.add(1,RED,4,"红色");
>         menu.add(1,GREEN,2,"绿色");
>         menu.add(1,BLUE,3,"蓝色");
>         menu.add(1,YELLOW,1,"黄色");
>         menu.add(1,GRAY,5,"灰色");
>         menu.add(1,CYAN,6,"蓝绿色");
>         menu.add(1,BLACK,7,"黑色");
>         return true;
>     }
> 
>     @Override
>     public boolean onOptionsItemSelected(MenuItem item) {
>         // Handle action bar item clicks here. The action bar will
>         // automatically handle clicks on the Home/Up button, so long
>         // as you specify a parent activity in AndroidManifest.xml.
>         int id = item.getItemId();
>         switch (id){
>             case RED:
>                 tv_test.setTextColor(Color.RED);
>                 break;
>             case GREEN:
>                 tv_test.setTextColor(Color.GREEN);
>                 break;
>             case BLUE:
>                 tv_test.setTextColor(Color.BLUE);
>                 break;
>             case YELLOW:
>                 tv_test.setTextColor(Color.YELLOW);
>                 break;
>             case GRAY:
>                 tv_test.setTextColor(Color.GRAY);
>                 break;
>             case CYAN:
>                 tv_test.setTextColor(Color.CYAN);
>                 break;
>             case BLACK:
>                 tv_test.setTextColor(Color.BLACK);
>                 break;
>         }
>         return super.onOptionsItemSelected(item);
>     }
> }
> ```

## 三、监听器：

有了这些部件之后我们需要有互动的功能，因此需要一些监听器来获取我们的信号源进行操作，例如点击，你要做出响应。

在监听器中，我们比较常见的有几种类型，例如对于点击按钮的监听器，第一种是直接匿名内部类，就是对于某个部件直接直接进行setXXXlistener，然后重写它的相关函数，例如onClick函数；第二种就是同样的你可以定义一个类似的外部类或者内部类来实现功能。第三种就是直接将活动作为事件监听器，可以重写onClick函数。

## 四、回调

监听器是对于某个动作的监听之后进行操作，而回调类似的，是对某个事件组件自己的处理方法，可以这么理解，就是我们对于回调的使用就是对于组件类的重写，例如：

> *①在该组件上触发屏幕事件: boolean* **onTouchEvent***(MotionEvent event);*
> *②在该组件上按下某个按钮时: boolean* **onKeyDown***(int keyCode,KeyEvent event);*
> *③松开组件上的某个按钮时: boolean* **onKeyUp***(int keyCode,KeyEvent event);*
> *④长按组件某个按钮时: boolean* **onKeyLongPress***(int keyCode,KeyEvent event);*
> *⑤键盘快捷键事件发生: boolean* **onKeyShortcut***(int keyCode,KeyEvent event);*
> *⑥在组件上触发轨迹球屏事件: boolean* **onTrackballEvent***(MotionEvent event);*
> **⑦当组件的焦点发生改变,和前面的6个不同,这个方法只能够在View中重写哦！ protected void* **onFocusChanged***(boolean gainFocus, int direction, Rect previously FocusedRect)*

