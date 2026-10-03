#pragma once

// The region-of-interest editor (app/gui/RoiEditor.h) and the region row on
// the training screen. `roi`, `off` and file names stay as they are in every
// language: they are what the folder and --roi-region spell.

#include "i18n/BeginCatalog.h"

namespace spirula {
namespace i18n {
namespace msg {
namespace roi {

// ===========================================================================
// Opening it
// ===========================================================================

SS_MSG(editor_button,
    EN("Region of Interest"), JA("関心領域"), ZH_HANS("感兴趣区域"), ZH_HANT("感興趣區域"),
    KO("관심 영역"), DE("Interessenbereich"), FR("Région d'intérêt"), ES("Región de interés"),
    PT("Região de interesse"), IT("Regione di interesse"), NL("Interessegebied"),
    RU("Область интереса"), TR("İlgi Bölgesi"));

SS_MSG(editor_button_help,
    EN("Mark the part of the scene to train with boxes, ellipsoids, cylinders and "
       "outlines, added together or cut from each other. The trainer uses the saved "
       "region on its own."),
    JA("学習するシーンの範囲を、ボックス・楕円体・円柱・輪郭を足したり切り抜いたり"
       "して指定します。保存した領域はトレーナーが自動で使います。"),
    ZH_HANS("用盒、椭球、圆柱和轮廓相加或相减，标出要训练的场景范围。保存的区域会被"
            "训练器自动使用。"),
    ZH_HANT("用盒、橢球、圓柱和輪廓相加或相減，標出要訓練的場景範圍。儲存的區域會被"
            "訓練器自動使用。"),
    KO("상자, 타원체, 원기둥, 윤곽을 더하거나 잘라 내어 학습할 장면 범위를 지정합니다. "
       "저장한 영역은 트레이너가 자동으로 사용합니다."),
    DE("Den zu trainierenden Teil der Szene mit Quadern, Ellipsoiden, Zylindern und "
       "Umrissen markieren, die addiert oder voneinander abgezogen werden. Der Trainer "
       "nutzt den gespeicherten Bereich von selbst."),
    FR("Délimiter la partie de la scène à entraîner avec des boîtes, ellipsoïdes, "
       "cylindres et contours, ajoutés ou découpés les uns des autres. L'entraînement "
       "utilise la région enregistrée de lui-même."),
    ES("Marcar la parte de la escena que se entrena con cajas, elipsoides, cilindros y "
       "contornos, sumados o recortados entre sí. El entrenador usa la región guardada "
       "por sí solo."),
    PT("Marcar a parte da cena a treinar com caixas, elipsoides, cilindros e "
       "contornos, somados ou recortados uns dos outros. O treino usa a região guardada "
       "por si só."),
    IT("Delimitare la parte della scena da addestrare con scatole, ellissoidi, "
       "cilindri e contorni, sommati o ritagliati l'uno dall'altro. L'addestramento usa "
       "da solo la regione salvata."),
    NL("Het te trainen deel van de scène aangeven met dozen, ellipsoïden, cilinders en "
       "omtrekken, opgeteld of van elkaar afgetrokken. De trainer gebruikt het "
       "opgeslagen gebied vanzelf."),
    RU("Отметить обучаемую часть сцены коробками, эллипсоидами, цилиндрами и "
       "контурами, складывая их или вырезая друг из друга. Сохранённую область "
       "обучение использует само."),
    TR("Eğitilecek sahne bölümünü kutular, elipsoitler, silindirler ve ana hatlarla, "
       "bunları toplayarak ya da birbirinden keserek işaretleyin. Kaydedilen bölgeyi "
       "eğitim kendiliğinden kullanır."));

SS_MSG(editor_title,
    EN("Region of Interest"), JA("関心領域"), ZH_HANS("感兴趣区域"), ZH_HANT("感興趣區域"),
    KO("관심 영역"), DE("Interessenbereich"), FR("Région d'intérêt"), ES("Región de interés"),
    PT("Região de interesse"), IT("Regione di interesse"), NL("Interessegebied"),
    RU("Область интереса"), TR("İlgi Bölgesi"));

// ===========================================================================
// The file
// ===========================================================================

SS_MSG(lbl_region,
    EN("Region"), JA("領域"), ZH_HANS("区域"), ZH_HANT("區域"), KO("영역"), DE("Bereich"),
    FR("Région"), ES("Región"), PT("Região"), IT("Regione"), NL("Gebied"), RU("Область"),
    TR("Bölge"));

SS_MSG(file_new,
    EN("(new region)"), JA("（新しい領域）"), ZH_HANS("（新区域）"), ZH_HANT("（新區域）"),
    KO("(새 영역)"), DE("(neuer Bereich)"), FR("(nouvelle région)"), ES("(región nueva)"),
    PT("(nova região)"), IT("(nuova regione)"), NL("(nieuw gebied)"), RU("(новая область)"),
    TR("(yeni bölge)"));

SS_MSG(file_default_note,
    EN("Training uses {0} unless another region is picked on the training screen."),
    JA("学習画面で別の領域を選ばない限り、{0} が学習に使われます。"),
    ZH_HANS("除非在训练界面选择其他区域，训练使用 {0}。"),
    ZH_HANT("除非在訓練畫面選擇其他區域，訓練使用 {0}。"),
    KO("학습 화면에서 다른 영역을 고르지 않으면 학습에 {0}이(가) 쓰입니다."),
    DE("Das Training nutzt {0}, solange auf dem Trainingsbildschirm kein anderer "
       "Bereich gewählt ist."),
    FR("L'entraînement utilise {0}, sauf si une autre région est choisie sur l'écran "
       "d'entraînement."),
    ES("El entrenamiento usa {0} salvo que se elija otra región en la pantalla de "
       "entrenamiento."),
    PT("O treino usa {0}, a menos que outra região seja escolhida no ecrã de treino."),
    IT("L'addestramento usa {0}, a meno che non si scelga un'altra regione nella "
       "schermata di addestramento."),
    NL("De training gebruikt {0}, tenzij op het trainingsscherm een ander gebied is "
       "gekozen."),
    RU("Обучение использует {0}, если на экране обучения не выбрана другая область."),
    TR("Eğitim ekranında başka bir bölge seçilmedikçe eğitim {0} dosyasını kullanır."));

SS_MSG(no_files_note,
    EN("Nothing saved yet. Once saved, a region is used for training on its own."),
    JA("まだ何も保存されていません。保存した領域は自動で学習に使われます。"),
    ZH_HANS("尚未保存任何区域。保存后，区域会被自动用于训练。"),
    ZH_HANT("尚未儲存任何區域。儲存後，區域會被自動用於訓練。"),
    KO("아직 저장된 것이 없습니다. 저장한 영역은 자동으로 학습에 쓰입니다."),
    DE("Noch nichts gespeichert. Ein gespeicherter Bereich wird beim Training von "
       "selbst genutzt."),
    FR("Rien n'est encore enregistré. Une fois enregistrée, une région sert à "
       "l'entraînement d'elle-même."),
    ES("Aún no hay nada guardado. Una vez guardada, la región se usa al entrenar por "
       "sí sola."),
    PT("Ainda nada foi guardado. Depois de guardada, a região é usada no treino por si "
       "só."),
    IT("Non è ancora salvato nulla. Una volta salvata, la regione viene usata "
       "nell'addestramento da sola."),
    NL("Nog niets opgeslagen. Een opgeslagen gebied wordt vanzelf bij het trainen "
       "gebruikt."),
    RU("Пока ничего не сохранено. Сохранённая область используется при обучении "
       "сама."),
    TR("Henüz bir şey kaydedilmedi. Kaydedilen bölge eğitimde kendiliğinden "
       "kullanılır."));

SS_MSG(lbl_name,
    EN("Name"), JA("名前"), ZH_HANS("名称"), ZH_HANT("名稱"), KO("이름"), DE("Name"),
    FR("Nom"), ES("Nombre"), PT("Nome"), IT("Nome"), NL("Naam"), RU("Имя"), TR("Ad"));

SS_MSG(btn_delete,
    EN("Delete"), JA("削除"), ZH_HANS("删除"), ZH_HANT("刪除"), KO("삭제"), DE("Löschen"),
    FR("Supprimer"), ES("Eliminar"), PT("Eliminar"), IT("Elimina"), NL("Verwijderen"),
    RU("Удалить"), TR("Sil"));

SS_MSG(delete_title,
    EN("Delete this region?"), JA("この領域を削除しますか？"), ZH_HANS("删除这个区域？"),
    ZH_HANT("刪除這個區域？"), KO("이 영역을 삭제할까요?"), DE("Diesen Bereich löschen?"),
    FR("Supprimer cette région ?"), ES("¿Eliminar esta región?"),
    PT("Eliminar esta região?"), IT("Eliminare questa regione?"),
    NL("Dit gebied verwijderen?"), RU("Удалить эту область?"), TR("Bu bölge silinsin mi?"));

SS_MSG(delete_body,
    EN("{0} will be deleted from the dataset's roi folder."),
    JA("{0} をデータセットの roi フォルダから削除します。"),
    ZH_HANS("将从数据集的 roi 文件夹中删除 {0}。"),
    ZH_HANT("將從資料集的 roi 資料夾中刪除 {0}。"),
    KO("데이터셋의 roi 폴더에서 {0}을(를) 삭제합니다."),
    DE("{0} wird aus dem roi-Ordner des Datensatzes gelöscht."),
    FR("{0} sera supprimé du dossier roi du jeu de données."),
    ES("{0} se eliminará de la carpeta roi del conjunto de datos."),
    PT("{0} será eliminado da pasta roi do conjunto de dados."),
    IT("{0} sarà eliminato dalla cartella roi del dataset."),
    NL("{0} wordt uit de roi-map van de dataset verwijderd."),
    RU("{0} будет удалён из папки roi набора данных."),
    TR("{0}, veri kümesinin roi klasöründen silinecek."));

SS_MSG(saved_to,
    EN("Saved to {0}"), JA("{0} に保存しました"), ZH_HANS("已保存到 {0}"),
    ZH_HANT("已儲存到 {0}"), KO("{0}에 저장했습니다"), DE("Gespeichert unter {0}"),
    FR("Enregistré dans {0}"), ES("Guardado en {0}"), PT("Guardado em {0}"),
    IT("Salvato in {0}"), NL("Opgeslagen in {0}"), RU("Сохранено в {0}"),
    TR("{0} konumuna kaydedildi"));

SS_MSG(name_taken,
    EN("Another region is already called {0}."), JA("{0} という名前の領域はすでにあります。"),
    ZH_HANS("已有名为 {0} 的区域。"), ZH_HANT("已有名為 {0} 的區域。"),
    KO("{0}(이)라는 영역이 이미 있습니다."), DE("Ein anderer Bereich heißt bereits {0}."),
    FR("Une autre région s'appelle déjà {0}."), ES("Ya hay otra región llamada {0}."),
    PT("Já existe outra região chamada {0}."), IT("Esiste già un'altra regione di nome {0}."),
    NL("Er is al een ander gebied met de naam {0}."), RU("Другая область уже называется {0}."),
    TR("{0} adında başka bir bölge zaten var."));

SS_MSG(nothing_to_save,
    EN("Add a shape first: there is nothing to save yet."),
    JA("先に図形を追加してください。まだ保存するものがありません。"),
    ZH_HANS("请先添加形状：目前还没有可保存的内容。"),
    ZH_HANT("請先新增形狀：目前還沒有可儲存的內容。"),
    KO("먼저 도형을 추가하세요. 아직 저장할 것이 없습니다."),
    DE("Zuerst eine Form hinzufügen: Noch gibt es nichts zu speichern."),
    FR("Ajoutez d'abord une forme : il n'y a encore rien à enregistrer."),
    ES("Primero añade una forma: todavía no hay nada que guardar."),
    PT("Primeiro adicione uma forma: ainda não há nada para guardar."),
    IT("Aggiungi prima una forma: non c'è ancora nulla da salvare."),
    NL("Voeg eerst een vorm toe: er is nog niets om op te slaan."),
    RU("Сначала добавьте фигуру: сохранять пока нечего."),
    TR("Önce bir şekil ekleyin: henüz kaydedilecek bir şey yok."));

SS_MSG(not_editable,
    EN("This file is not a list of shapes this editor can show. It is still used for "
       "training as it is."),
    JA("このファイルはこのエディタで表示できる図形のリストではありません。学習にはそ"
       "のまま使われます。"),
    ZH_HANS("此文件不是本编辑器能显示的形状列表，但训练仍会按原样使用它。"),
    ZH_HANT("此檔案不是本編輯器能顯示的形狀列表，但訓練仍會按原樣使用它。"),
    KO("이 파일은 이 편집기가 보여 줄 수 있는 도형 목록이 아닙니다. 학습에는 그대로 "
       "쓰입니다."),
    DE("Diese Datei ist keine Liste von Formen, die dieser Editor zeigen kann. Das "
       "Training nutzt sie trotzdem unverändert."),
    FR("Ce fichier n'est pas une liste de formes que cet éditeur sait afficher. "
       "L'entraînement l'utilise tout de même tel quel."),
    ES("Este archivo no es una lista de formas que este editor pueda mostrar. El "
       "entrenamiento lo usa igualmente tal cual."),
    PT("Este ficheiro não é uma lista de formas que este editor consiga mostrar. O "
       "treino usa-o mesmo assim tal como está."),
    IT("Questo file non è un elenco di forme che questo editor sa mostrare. "
       "L'addestramento lo usa comunque così com'è."),
    NL("Dit bestand is geen lijst met vormen die deze editor kan tonen. De training "
       "gebruikt het toch zoals het is."),
    RU("Этот файл не является списком фигур, который может показать редактор. "
       "Обучение всё равно использует его как есть."),
    TR("Bu dosya, bu düzenleyicinin gösterebileceği bir şekil listesi değil. Eğitim "
       "onu yine de olduğu gibi kullanır."));

SS_MSG(unsaved,
    EN("Unsaved changes"), JA("未保存の変更"), ZH_HANS("有未保存的更改"),
    ZH_HANT("有未儲存的變更"), KO("저장하지 않은 변경 사항"),
    DE("Ungespeicherte Änderungen"), FR("Modifications non enregistrées"),
    ES("Cambios sin guardar"), PT("Alterações por guardar"), IT("Modifiche non salvate"),
    NL("Niet-opgeslagen wijzigingen"), RU("Есть несохранённые изменения"),
    TR("Kaydedilmemiş değişiklikler"));

// ===========================================================================
// Starting points
// ===========================================================================

SS_MSG(start_head,
    EN("Start from"), JA("最初の形"), ZH_HANS("起点"), ZH_HANT("起點"), KO("시작점"),
    DE("Ausgangspunkt"), FR("Point de départ"), ES("Punto de partida"),
    PT("Ponto de partida"), IT("Punto di partenza"), NL("Beginpunt"),
    RU("С чего начать"), TR("Başlangıç"));

SS_MSG(start_box,
    EN("Box Around the Scene"), JA("シーンを囲むボックス"), ZH_HANS("包围场景的盒"),
    ZH_HANT("包圍場景的盒"), KO("장면을 감싸는 상자"), DE("Quader um die Szene"),
    FR("Boîte autour de la scène"), ES("Caja alrededor de la escena"),
    PT("Caixa à volta da cena"), IT("Scatola attorno alla scena"),
    NL("Doos om de scène"), RU("Коробка вокруг сцены"), TR("Sahneyi Saran Kutu"));

SS_MSG(start_box_help,
    EN("A box around the points, turned to fit them: a good start for most captures."),
    JA("点群を囲み、向きを合わせたボックス。たいていの撮影に向いた出発点です。"),
    ZH_HANS("包围点云并转向贴合它们的盒，适合大多数拍摄作为起点。"),
    ZH_HANT("包圍點雲並轉向貼合它們的盒，適合大多數拍攝作為起點。"),
    KO("점들을 감싸고 방향을 맞춘 상자로, 대부분의 촬영에 좋은 출발점입니다."),
    DE("Ein Quader um die Punkte, passend gedreht: für die meisten Aufnahmen ein guter "
       "Anfang."),
    FR("Une boîte autour des points, tournée pour les épouser : un bon départ pour la "
       "plupart des captures."),
    ES("Una caja alrededor de los puntos, girada para ajustarse a ellos: un buen "
       "comienzo para casi cualquier captura."),
    PT("Uma caixa à volta dos pontos, rodada para se ajustar a eles: um bom começo "
       "para a maioria das capturas."),
    IT("Una scatola attorno ai punti, ruotata per adattarsi: un buon inizio per la "
       "maggior parte delle riprese."),
    NL("Een doos om de punten, gedraaid zodat hij past: een goed begin voor de meeste "
       "opnamen."),
    RU("Коробка вокруг точек, повёрнутая по ним: хорошее начало для большинства "
       "съёмок."),
    TR("Noktaları saran ve onlara göre döndürülmüş bir kutu: çoğu çekim için iyi bir "
       "başlangıç."));

SS_MSG(start_cylinder,
    EN("Cylinder Around the Subject"), JA("被写体を囲む円柱"), ZH_HANS("包围主体的圆柱"),
    ZH_HANT("包圍主體的圓柱"), KO("피사체를 감싸는 원기둥"), DE("Zylinder um das Motiv"),
    FR("Cylindre autour du sujet"), ES("Cilindro alrededor del sujeto"),
    PT("Cilindro à volta do motivo"), IT("Cilindro attorno al soggetto"),
    NL("Cilinder om het onderwerp"), RU("Цилиндр вокруг объекта"),
    TR("Öznenin Etrafında Silindir"));

SS_MSG(start_cylinder_help,
    EN("For a capture that walks around one subject: an upright cylinder where the "
       "cameras look, inside the circle they stand on."),
    JA("ひとつの被写体の周りを回って撮った場合に。カメラが見つめる場所に、カメラが"
       "並ぶ円の内側に収まる直立した円柱を置きます。"),
    ZH_HANS("适合绕着一个主体拍摄的情形：在相机注视处放一个直立圆柱，位于相机所站的圆"
            "圈之内。"),
    ZH_HANT("適合繞著一個主體拍攝的情形：在相機注視處放一個直立圓柱，位於相機所站的圓"
            "圈之內。"),
    KO("한 피사체 둘레를 돌며 찍은 경우에: 카메라가 바라보는 곳에, 카메라가 선 원 "
       "안쪽으로 곧게 선 원기둥을 둡니다."),
    DE("Für eine Aufnahme rund um ein Motiv: ein aufrechter Zylinder dort, wohin die "
       "Kameras blicken, innerhalb des Kreises, auf dem sie stehen."),
    FR("Pour une capture qui tourne autour d'un sujet : un cylindre droit là où "
       "regardent les caméras, à l'intérieur du cercle qu'elles forment."),
    ES("Para una captura que rodea un sujeto: un cilindro vertical donde miran las "
       "cámaras, dentro del círculo que forman."),
    PT("Para uma captura feita à volta de um motivo: um cilindro vertical onde as "
       "câmaras olham, dentro do círculo em que estão."),
    IT("Per una ripresa fatta girando attorno a un soggetto: un cilindro verticale dove "
       "guardano le fotocamere, dentro il cerchio su cui stanno."),
    NL("Voor een opname rondom één onderwerp: een rechtopstaande cilinder waar de "
       "camera's naar kijken, binnen de cirkel waarop ze staan."),
    RU("Для съёмки по кругу вокруг одного объекта: вертикальный цилиндр там, куда "
       "смотрят камеры, внутри круга, на котором они стоят."),
    TR("Tek bir öznenin etrafında dolaşarak yapılan çekim için: kameraların baktığı "
       "yerde, durdukları çemberin içinde dik bir silindir."));

SS_MSG(start_cylinder_off,
    EN("The cameras do not circle one subject."),
    JA("カメラがひとつの被写体を囲んでいません。"),
    ZH_HANS("相机并未环绕同一个主体。"),
    ZH_HANT("相機並未環繞同一個主體。"),
    KO("카메라가 한 피사체를 둘러싸고 있지 않습니다."),
    DE("Die Kameras umkreisen kein einzelnes Motiv."),
    FR("Les caméras ne tournent pas autour d'un même sujet."),
    ES("Las cámaras no rodean un único sujeto."),
    PT("As câmaras não rodeiam um único motivo."),
    IT("Le fotocamere non girano attorno a un unico soggetto."),
    NL("De camera's staan niet rond één onderwerp."),
    RU("Камеры не окружают один объект."),
    TR("Kameralar tek bir öznenin etrafını sarmıyor."));

SS_MSG(start_outline,
    EN("Outline Drawn from Above"), JA("上から描く輪郭"), ZH_HANS("从上方绘制轮廓"),
    ZH_HANT("從上方繪製輪廓"), KO("위에서 그리는 윤곽"), DE("Umriss von oben gezeichnet"),
    FR("Contour tracé vu de dessus"), ES("Contorno dibujado desde arriba"),
    PT("Contorno desenhado de cima"), IT("Contorno disegnato dall'alto"),
    NL("Omtrek van bovenaf getekend"), RU("Контур, нарисованный сверху"),
    TR("Yukarıdan Çizilen Ana Hat"));

SS_MSG(start_outline_help,
    EN("Click the corners of the area in a view from above. The outline is raised to "
       "the height of the points inside it."),
    JA("上からの視点で範囲の角をクリックします。輪郭は内側の点の高さまで立ち上げられ"
       "ます。"),
    ZH_HANS("在俯视图中点击区域的各个角。轮廓会被拉伸到其内部点云的高度。"),
    ZH_HANT("在俯視圖中點擊區域的各個角。輪廓會被拉伸到其內部點雲的高度。"),
    KO("위에서 본 화면에서 영역의 모서리를 클릭합니다. 윤곽은 안쪽 점들의 높이까지 "
       "세워집니다."),
    DE("In einer Ansicht von oben die Ecken des Gebiets anklicken. Der Umriss wird bis "
       "zur Höhe der Punkte darin hochgezogen."),
    FR("Cliquez les coins de la zone dans une vue de dessus. Le contour est élevé à la "
       "hauteur des points qu'il contient."),
    ES("Haz clic en las esquinas de la zona en una vista desde arriba. El contorno se "
       "eleva hasta la altura de los puntos que contiene."),
    PT("Clique nos cantos da área numa vista de cima. O contorno é levantado até à "
       "altura dos pontos que contém."),
    IT("Fai clic sugli angoli dell'area in una vista dall'alto. Il contorno viene "
       "alzato fino all'altezza dei punti al suo interno."),
    NL("Klik in een bovenaanzicht op de hoeken van het gebied. De omtrek wordt "
       "opgetrokken tot de hoogte van de punten erin."),
    RU("Щёлкните углы области в виде сверху. Контур поднимается до высоты точек "
       "внутри него."),
    TR("Yukarıdan bakan bir görünümde alanın köşelerine tıklayın. Ana hat, içindeki "
       "noktaların yüksekliğine kadar yükseltilir."));

// ===========================================================================
// The shapes
// ===========================================================================

SS_MSG(shapes_head,
    EN("Shapes"), JA("図形"), ZH_HANS("形状"), ZH_HANT("形狀"), KO("도형"), DE("Formen"),
    FR("Formes"), ES("Formas"), PT("Formas"), IT("Forme"), NL("Vormen"), RU("Фигуры"),
    TR("Şekiller"));

SS_MSG(btn_add,
    EN("Add Shape"), JA("図形を追加"), ZH_HANS("添加形状"), ZH_HANT("新增形狀"),
    KO("도형 추가"), DE("Form hinzufügen"), FR("Ajouter une forme"), ES("Añadir forma"),
    PT("Adicionar forma"), IT("Aggiungi forma"), NL("Vorm toevoegen"),
    RU("Добавить фигуру"), TR("Şekil Ekle"));

SS_MSG(kind_box,
    EN("Box"), JA("ボックス"), ZH_HANS("盒"), ZH_HANT("盒"), KO("상자"), DE("Quader"),
    FR("Boîte"), ES("Caja"), PT("Caixa"), IT("Scatola"), NL("Doos"), RU("Коробка"),
    TR("Kutu"));

SS_MSG(kind_ellipsoid,
    EN("Ellipsoid"), JA("楕円体"), ZH_HANS("椭球"), ZH_HANT("橢球"), KO("타원체"),
    DE("Ellipsoid"), FR("Ellipsoïde"), ES("Elipsoide"), PT("Elipsoide"), IT("Ellissoide"),
    NL("Ellipsoïde"), RU("Эллипсоид"), TR("Elipsoit"));

SS_MSG(kind_cylinder,
    EN("Cylinder"), JA("円柱"), ZH_HANS("圆柱"), ZH_HANT("圓柱"), KO("원기둥"),
    DE("Zylinder"), FR("Cylindre"), ES("Cilindro"), PT("Cilindro"), IT("Cilindro"),
    NL("Cilinder"), RU("Цилиндр"), TR("Silindir"));

SS_MSG(kind_prism,
    EN("Outline"), JA("輪郭"), ZH_HANS("轮廓"), ZH_HANT("輪廓"), KO("윤곽"), DE("Umriss"),
    FR("Contour"), ES("Contorno"), PT("Contorno"), IT("Contorno"), NL("Omtrek"),
    RU("Контур"), TR("Ana hat"));

SS_MSG(name_box,
    EN("Box {0}"), JA("ボックス {0}"), ZH_HANS("盒 {0}"), ZH_HANT("盒 {0}"), KO("상자 {0}"),
    DE("Quader {0}"), FR("Boîte {0}"), ES("Caja {0}"), PT("Caixa {0}"), IT("Scatola {0}"),
    NL("Doos {0}"), RU("Коробка {0}"), TR("Kutu {0}"));

SS_MSG(name_ellipsoid,
    EN("Ellipsoid {0}"), JA("楕円体 {0}"), ZH_HANS("椭球 {0}"), ZH_HANT("橢球 {0}"),
    KO("타원체 {0}"), DE("Ellipsoid {0}"), FR("Ellipsoïde {0}"), ES("Elipsoide {0}"),
    PT("Elipsoide {0}"), IT("Ellissoide {0}"), NL("Ellipsoïde {0}"), RU("Эллипсоид {0}"),
    TR("Elipsoit {0}"));

SS_MSG(name_cylinder,
    EN("Cylinder {0}"), JA("円柱 {0}"), ZH_HANS("圆柱 {0}"), ZH_HANT("圓柱 {0}"),
    KO("원기둥 {0}"), DE("Zylinder {0}"), FR("Cylindre {0}"), ES("Cilindro {0}"),
    PT("Cilindro {0}"), IT("Cilindro {0}"), NL("Cilinder {0}"), RU("Цилиндр {0}"),
    TR("Silindir {0}"));

SS_MSG(name_prism,
    EN("Outline {0}"), JA("輪郭 {0}"), ZH_HANS("轮廓 {0}"), ZH_HANT("輪廓 {0}"),
    KO("윤곽 {0}"), DE("Umriss {0}"), FR("Contour {0}"), ES("Contorno {0}"),
    PT("Contorno {0}"), IT("Contorno {0}"), NL("Omtrek {0}"), RU("Контур {0}"),
    TR("Ana hat {0}"));

SS_MSG(btn_duplicate,
    EN("Duplicate"), JA("複製"), ZH_HANS("复制"), ZH_HANT("複製"), KO("복제"),
    DE("Duplizieren"), FR("Dupliquer"), ES("Duplicar"), PT("Duplicar"), IT("Duplica"),
    NL("Dupliceren"), RU("Дублировать"), TR("Çoğalt"));

SS_MSG(btn_remove,
    EN("Remove"), JA("取り除く"), ZH_HANS("移除"), ZH_HANT("移除"), KO("제거"),
    DE("Entfernen"), FR("Retirer"), ES("Quitar"), PT("Remover"), IT("Rimuovi"),
    NL("Verwijderen"), RU("Убрать"), TR("Kaldır"));

SS_MSG(op_add,
    EN("Add"), JA("足す"), ZH_HANS("相加"), ZH_HANT("相加"), KO("더하기"),
    DE("Addieren"), FR("Ajouter"), ES("Sumar"), PT("Somar"), IT("Aggiungi"),
    NL("Optellen"), RU("Добавить"), TR("Ekle"));

SS_MSG(op_cut,
    EN("Cut"), JA("切り抜く"), ZH_HANS("挖去"), ZH_HANT("挖去"), KO("잘라 내기"),
    DE("Ausschneiden"), FR("Découper"), ES("Recortar"), PT("Recortar"), IT("Ritaglia"),
    NL("Uitsnijden"), RU("Вырезать"), TR("Kes"));

SS_MSG(op_overlap,
    EN("Overlap"), JA("重なり"), ZH_HANS("交叠"), ZH_HANT("交疊"), KO("겹침"),
    DE("Überschneidung"), FR("Recouvrement"), ES("Solapamiento"), PT("Sobreposição"),
    IT("Sovrapposizione"), NL("Overlap"), RU("Пересечение"), TR("Kesişim"));

SS_MSG(op_help,
    EN("Add joins the shape to the shapes above it, Cut removes it from them, and "
       "Overlap keeps only where it overlaps them. A list that starts with a cut keeps "
       "everything else."),
    JA("「足す」は上の図形に加え、「切り抜く」は上の図形から取り除き、「重なり」は重"
       "なる所だけを残します。切り抜きで始まるリストは、それ以外のすべてを残します。"),
    ZH_HANS("“相加”把形状并入上方的形状，“挖去”从中移除它，“交叠”只保留重叠之处。"
            "以挖去开头的列表会保留其余一切。"),
    ZH_HANT("「相加」把形狀併入上方的形狀，「挖去」從中移除它，「交疊」只保留重疊之處。"
            "以挖去開頭的列表會保留其餘一切。"),
    KO("더하기는 위쪽 도형에 합치고, 잘라 내기는 거기서 빼며, 겹침은 겹치는 곳만 "
       "남깁니다. 잘라 내기로 시작하는 목록은 그 밖의 모든 곳을 남깁니다."),
    DE("Addieren fügt die Form zu den Formen darüber hinzu, Ausschneiden nimmt sie "
       "heraus, Überschneidung behält nur, wo sie sich überlappen. Eine Liste, die mit "
       "einem Ausschnitt beginnt, behält alles andere."),
    FR("Ajouter joint la forme aux formes au-dessus, Découper l'en retire et "
       "Recouvrement ne garde que là où elles se recouvrent. Une liste qui commence par "
       "une découpe garde tout le reste."),
    ES("Sumar une la forma a las formas de encima, Recortar la quita de ellas y "
       "Solapamiento conserva solo donde se solapan. Una lista que empieza por un "
       "recorte conserva todo lo demás."),
    PT("Somar junta a forma às formas acima, Recortar retira-a delas e Sobreposição "
       "mantém apenas onde se sobrepõem. Uma lista que começa por um recorte mantém "
       "todo o resto."),
    IT("Aggiungi unisce la forma a quelle sopra, Ritaglia la toglie da esse e "
       "Sovrapposizione tiene solo dove si sovrappongono. Un elenco che inizia con un "
       "ritaglio tiene tutto il resto."),
    NL("Optellen voegt de vorm bij de vormen erboven, Uitsnijden haalt hem eruit en "
       "Overlap houdt alleen over waar ze overlappen. Een lijst die met een uitsnede "
       "begint, houdt al het andere."),
    RU("«Добавить» присоединяет фигуру к фигурам выше, «Вырезать» удаляет её из них, а "
       "«Пересечение» оставляет только общую часть. Список, начинающийся с вырезания, "
       "оставляет всё остальное."),
    TR("Ekle, şekli üstteki şekillere katar; Kes, onları bu şekilden ayırır; Kesişim "
       "yalnızca örtüştükleri yeri bırakır. Kesme ile başlayan bir liste geri kalan her "
       "şeyi tutar."));

SS_MSG(list_empty,
    EN("No shapes yet. Start from one of the buttons above, or add a shape."),
    JA("まだ図形がありません。上のボタンのどれかから始めるか、図形を追加してください。"),
    ZH_HANS("还没有形状。从上方的某个按钮开始，或添加一个形状。"),
    ZH_HANT("還沒有形狀。從上方的某個按鈕開始，或新增一個形狀。"),
    KO("아직 도형이 없습니다. 위의 버튼 중 하나로 시작하거나 도형을 추가하세요."),
    DE("Noch keine Formen. Mit einer der Schaltflächen oben beginnen oder eine Form "
       "hinzufügen."),
    FR("Aucune forme pour l'instant. Commencez par l'un des boutons ci-dessus, ou "
       "ajoutez une forme."),
    ES("Todavía no hay formas. Empieza con uno de los botones de arriba o añade una "
       "forma."),
    PT("Ainda não há formas. Comece por um dos botões acima ou adicione uma forma."),
    IT("Ancora nessuna forma. Inizia da uno dei pulsanti qui sopra o aggiungi una "
       "forma."),
    NL("Nog geen vormen. Begin met een van de knoppen hierboven of voeg een vorm toe."),
    RU("Фигур пока нет. Начните с одной из кнопок выше или добавьте фигуру."),
    TR("Henüz şekil yok. Yukarıdaki düğmelerden biriyle başlayın ya da bir şekil "
       "ekleyin."));

SS_MSG(enabled_help,
    EN("Ticked shapes make up the region; an unticked one is kept but left out."),
    JA("チェックした図形が領域を作ります。チェックを外した図形は残りますが使われませ"
       "ん。"),
    ZH_HANS("勾选的形状组成区域；未勾选的形状会保留，但不参与。"),
    ZH_HANT("勾選的形狀組成區域；未勾選的形狀會保留，但不參與。"),
    KO("체크한 도형이 영역을 이룹니다. 체크를 해제한 도형은 남지만 빠집니다."),
    DE("Angehakte Formen bilden den Bereich; eine nicht angehakte bleibt erhalten, "
       "zählt aber nicht."),
    FR("Les formes cochées composent la région ; une forme décochée est conservée mais "
       "laissée de côté."),
    ES("Las formas marcadas componen la región; una desmarcada se conserva pero queda "
       "fuera."),
    PT("As formas marcadas compõem a região; uma desmarcada é mantida mas fica de fora."),
    IT("Le forme spuntate compongono la regione; una non spuntata resta ma è esclusa."),
    NL("Aangevinkte vormen vormen het gebied; een niet-aangevinkte blijft bestaan maar "
       "telt niet mee."),
    RU("Отмеченные фигуры составляют область; неотмеченная сохраняется, но не "
       "учитывается."),
    TR("İşaretli şekiller bölgeyi oluşturur; işaretsiz olan kalır ama dışarıda "
       "bırakılır."));

SS_MSG(lbl_position,
    EN("Position"), JA("位置"), ZH_HANS("位置"), ZH_HANT("位置"), KO("위치"),
    DE("Position"), FR("Position"), ES("Posición"), PT("Posição"), IT("Posizione"),
    NL("Positie"), RU("Положение"), TR("Konum"));

SS_MSG(lbl_size,
    EN("Size"), JA("サイズ"), ZH_HANS("尺寸"), ZH_HANT("尺寸"), KO("크기"), DE("Größe"),
    FR("Taille"), ES("Tamaño"), PT("Tamanho"), IT("Dimensioni"), NL("Afmeting"),
    RU("Размер"), TR("Boyut"));

SS_MSG(lbl_rotation,
    EN("Rotation"), JA("回転"), ZH_HANS("旋转"), ZH_HANT("旋轉"), KO("회전"),
    DE("Drehung"), FR("Rotation"), ES("Rotación"), PT("Rotação"), IT("Rotazione"),
    NL("Rotatie"), RU("Поворот"), TR("Döndürme"));

SS_MSG(lbl_height,
    EN("Height"), JA("高さ"), ZH_HANS("高度"), ZH_HANT("高度"), KO("높이"), DE("Höhe"),
    FR("Hauteur"), ES("Altura"), PT("Altura"), IT("Altezza"), NL("Hoogte"), RU("Высота"),
    TR("Yükseklik"));

SS_MSG(position_help,
    EN("The centre, in the dataset's own coordinates."),
    JA("中心。データセット自身の座標で表します。"),
    ZH_HANS("中心点，使用数据集自身的坐标。"),
    ZH_HANT("中心點，使用資料集自身的座標。"),
    KO("중심점으로, 데이터셋 자체의 좌표입니다."),
    DE("Der Mittelpunkt, in den eigenen Koordinaten des Datensatzes."),
    FR("Le centre, dans les coordonnées propres du jeu de données."),
    ES("El centro, en las coordenadas propias del conjunto de datos."),
    PT("O centro, nas coordenadas próprias do conjunto de dados."),
    IT("Il centro, nelle coordinate proprie del dataset."),
    NL("Het middelpunt, in de eigen coördinaten van de dataset."),
    RU("Центр в собственных координатах набора данных."),
    TR("Merkez, veri kümesinin kendi koordinatlarında."));

SS_MSG(size_help,
    EN("Lengths along the shape's own axes, in the dataset's units. Drag a handle in "
       "the view with Resize, or type a number."),
    JA("図形自身の軸に沿った長さ（データセットの単位）。ビューで「サイズ変更」のハンド"
       "ルをドラッグするか、数値を入力します。"),
    ZH_HANS("沿形状自身各轴的长度，单位与数据集相同。可在视图中用“缩放”拖动手柄，或直"
            "接输入数字。"),
    ZH_HANT("沿形狀自身各軸的長度，單位與資料集相同。可在視圖中用「縮放」拖動控點，或直"
            "接輸入數字。"),
    KO("도형 자체 축을 따른 길이(데이터셋 단위). 보기에서 크기 조절 핸들을 끌거나 "
       "숫자를 입력합니다."),
    DE("Längen entlang der eigenen Achsen der Form, in Einheiten des Datensatzes. In "
       "der Ansicht mit Größe einen Griff ziehen oder eine Zahl eingeben."),
    FR("Longueurs le long des axes propres de la forme, en unités du jeu de données. "
       "Tirez une poignée dans la vue avec Redimensionner, ou tapez un nombre."),
    ES("Longitudes a lo largo de los ejes propios de la forma, en unidades del conjunto "
       "de datos. Arrastra un tirador en la vista con Redimensionar o escribe un número."),
    PT("Comprimentos ao longo dos eixos próprios da forma, nas unidades do conjunto de "
       "dados. Arraste uma pega na vista com Redimensionar ou escreva um número."),
    IT("Lunghezze lungo gli assi propri della forma, nelle unità del dataset. Trascina "
       "una maniglia nella vista con Ridimensiona o digita un numero."),
    NL("Lengtes langs de eigen assen van de vorm, in eenheden van de dataset. Sleep in "
       "de weergave een greep met Formaat of typ een getal."),
    RU("Длины вдоль собственных осей фигуры в единицах набора данных. Перетащите "
       "маркер в виде в режиме «Размер» или введите число."),
    TR("Şeklin kendi eksenleri boyunca uzunluklar, veri kümesinin biriminde. "
       "Görünümde Boyutlandır ile bir tutamacı sürükleyin ya da bir sayı yazın."));

SS_MSG(rotation_help,
    EN("Degrees: turned about the up axis, then tilted forward, then sideways."),
    JA("度数。上向きの軸のまわりに回し、次に前へ、次に横へ傾けます。"),
    ZH_HANS("角度：先绕向上的轴转动，再向前倾斜，再向侧面倾斜。"),
    ZH_HANT("角度：先繞向上的軸轉動，再向前傾斜，再向側面傾斜。"),
    KO("각도: 위쪽 축을 중심으로 돌린 뒤, 앞으로, 그다음 옆으로 기울입니다."),
    DE("Grad: um die Hochachse gedreht, dann nach vorn, dann seitlich gekippt."),
    FR("Degrés : tourné autour de l'axe vertical, puis incliné vers l'avant, puis sur "
       "le côté."),
    ES("Grados: girado sobre el eje vertical, luego inclinado hacia delante y luego de "
       "lado."),
    PT("Graus: rodado em torno do eixo vertical, depois inclinado para a frente e "
       "depois para o lado."),
    IT("Gradi: ruotato attorno all'asse verticale, poi inclinato in avanti, poi di "
       "lato."),
    NL("Graden: gedraaid om de verticale as, daarna naar voren en daarna opzij "
       "gekanteld."),
    RU("Градусы: поворот вокруг вертикальной оси, затем наклон вперёд, затем вбок."),
    TR("Derece: yukarı eksen etrafında döndürülür, sonra öne, sonra yana eğilir."));

SS_MSG(btn_level,
    EN("Level"), JA("水平に戻す"), ZH_HANS("放平"), ZH_HANT("放平"), KO("수평으로"),
    DE("Ausrichten"), FR("Remettre droit"), ES("Nivelar"), PT("Nivelar"), IT("Livella"),
    NL("Waterpas"), RU("Выровнять"), TR("Düzle"));

SS_MSG(btn_level_help,
    EN("Stand the shape upright again: its turn stays, its tilt goes."),
    JA("図形をまっすぐ立て直します。回転の向きはそのまま、傾きを取り除きます。"),
    ZH_HANS("把形状重新立直：保留转动，去掉倾斜。"),
    ZH_HANT("把形狀重新立直：保留轉動，去掉傾斜。"),
    KO("도형을 다시 곧게 세웁니다. 회전 방향은 그대로 두고 기울기만 없앱니다."),
    DE("Die Form wieder aufrecht stellen: Die Drehung bleibt, die Neigung geht."),
    FR("Redresser la forme : sa rotation reste, son inclinaison disparaît."),
    ES("Volver a poner la forma derecha: el giro se mantiene, la inclinación se va."),
    PT("Endireitar a forma: a rotação mantém-se, a inclinação desaparece."),
    IT("Raddrizzare la forma: la rotazione resta, l'inclinazione sparisce."),
    NL("De vorm weer rechtop zetten: de draaiing blijft, de kanteling verdwijnt."),
    RU("Снова поставить фигуру прямо: поворот сохраняется, наклон убирается."),
    TR("Şekli yeniden dik konuma getirir: dönüşü kalır, eğimi kaldırılır."));

SS_MSG(btn_redraw,
    EN("Redraw Outline"), JA("輪郭を描き直す"), ZH_HANS("重新绘制轮廓"),
    ZH_HANT("重新繪製輪廓"), KO("윤곽 다시 그리기"), DE("Umriss neu zeichnen"),
    FR("Retracer le contour"), ES("Redibujar el contorno"), PT("Redesenhar o contorno"),
    IT("Ridisegna il contorno"), NL("Omtrek opnieuw tekenen"),
    RU("Перерисовать контур"), TR("Ana Hattı Yeniden Çiz"));

SS_MSG(lbl_corners,
    EN("Corners: {0}"), JA("角の数: {0}"), ZH_HANS("角点：{0}"), ZH_HANT("角點：{0}"),
    KO("모서리: {0}"), DE("Ecken: {0}"), FR("Coins : {0}"), ES("Esquinas: {0}"),
    PT("Cantos: {0}"), IT("Angoli: {0}"), NL("Hoeken: {0}"), RU("Углов: {0}"),
    TR("Köşe: {0}"));

// ===========================================================================
// The view
// ===========================================================================

SS_MSG(mode_move,
    EN("Move"), JA("移動"), ZH_HANS("移动"), ZH_HANT("移動"), KO("이동"), DE("Bewegen"),
    FR("Déplacer"), ES("Mover"), PT("Mover"), IT("Sposta"), NL("Verplaatsen"),
    RU("Перемещение"), TR("Taşı"));

SS_MSG(mode_resize,
    EN("Resize"), JA("サイズ変更"), ZH_HANS("缩放"), ZH_HANT("縮放"), KO("크기 조절"),
    DE("Größe"), FR("Redimensionner"), ES("Redimensionar"), PT("Redimensionar"),
    IT("Ridimensiona"), NL("Formaat"), RU("Размер"), TR("Boyutlandır"));

SS_MSG(mode_rotate,
    EN("Rotate"), JA("回転"), ZH_HANS("旋转"), ZH_HANT("旋轉"), KO("회전"), DE("Drehen"),
    FR("Pivoter"), ES("Rotar"), PT("Rodar"), IT("Ruota"), NL("Draaien"), RU("Поворот"),
    TR("Döndür"));

SS_MSG(hint_none,
    EN("Click a shape to select it. Drag anywhere else to look around."),
    JA("図形をクリックして選択します。それ以外の場所をドラッグすると視点が回ります。"),
    ZH_HANS("点击形状以选中它。拖动其他任何地方可环顾四周。"),
    ZH_HANT("點擊形狀以選取它。拖動其他任何地方可環顧四周。"),
    KO("도형을 클릭해 선택합니다. 다른 곳을 끌면 둘러봅니다."),
    DE("Eine Form anklicken, um sie auszuwählen. Überall sonst ziehen, um sich "
       "umzusehen."),
    FR("Cliquez une forme pour la sélectionner. Faites glisser ailleurs pour regarder "
       "autour."),
    ES("Haz clic en una forma para seleccionarla. Arrastra en cualquier otro sitio "
       "para mirar alrededor."),
    PT("Clique numa forma para a selecionar. Arraste noutro sítio para olhar em volta."),
    IT("Fai clic su una forma per selezionarla. Trascina altrove per guardarti "
       "intorno."),
    NL("Klik op een vorm om hem te selecteren. Sleep ergens anders om rond te kijken."),
    RU("Щёлкните фигуру, чтобы выбрать её. Перетаскивание в другом месте вращает вид."),
    TR("Seçmek için bir şekle tıklayın. Etrafa bakmak için başka bir yeri sürükleyin."));

SS_MSG(hint_move,
    EN("Drag the shape along the ground, or an arrow along its axis. Delete removes it, "
       "Esc lets go of it."),
    JA("図形をドラッグすると地面に沿って、矢印をドラッグするとその軸に沿って動きます。"
       "Delete で削除、Esc で選択を解除します。"),
    ZH_HANS("拖动形状可沿地面移动，拖动箭头可沿其轴移动。Delete 删除，Esc 取消选中。"),
    ZH_HANT("拖動形狀可沿地面移動，拖動箭頭可沿其軸移動。Delete 刪除，Esc 取消選取。"),
    KO("도형을 끌면 바닥을 따라, 화살표를 끌면 그 축을 따라 움직입니다. Delete로 "
       "삭제하고 Esc로 선택을 해제합니다."),
    DE("Die Form am Boden entlang ziehen oder einen Pfeil entlang seiner Achse. Entf "
       "entfernt sie, Esc lässt sie los."),
    FR("Faites glisser la forme le long du sol, ou une flèche le long de son axe. "
       "Suppr la retire, Échap la désélectionne."),
    ES("Arrastra la forma por el suelo, o una flecha a lo largo de su eje. Supr la "
       "quita, Esc la suelta."),
    PT("Arraste a forma ao longo do chão, ou uma seta ao longo do seu eixo. Delete "
       "remove-a, Esc larga-a."),
    IT("Trascina la forma lungo il suolo, o una freccia lungo il suo asse. Canc la "
       "rimuove, Esc la lascia."),
    NL("Sleep de vorm over de grond, of een pijl langs zijn as. Delete verwijdert hem, "
       "Esc laat hem los."),
    RU("Тащите фигуру по земле или стрелку вдоль её оси. Delete убирает фигуру, Esc "
       "снимает выбор."),
    TR("Şekli zemin boyunca ya da bir oku kendi ekseni boyunca sürükleyin. Delete onu "
       "kaldırır, Esc seçimi bırakır."));

SS_MSG(hint_resize,
    EN("Drag a handle to move that side; with Shift both sides move. On an outline, "
       "drag a corner, drag a midpoint to add one, double-click a corner to remove it."),
    JA("ハンドルをドラッグするとその面が動き、Shift を押すと両側が動きます。輪郭では角"
       "をドラッグし、中点をドラッグして角を追加し、角をダブルクリックして削除します。"),
    ZH_HANS("拖动手柄移动该面；按住 Shift 两侧一起移动。对轮廓，可拖动角点，拖动中点以"
            "添加角点，双击角点将其删除。"),
    ZH_HANT("拖動控點移動該面；按住 Shift 兩側一起移動。對輪廓，可拖動角點，拖動中點以"
            "新增角點，雙擊角點將其刪除。"),
    KO("핸들을 끌면 그 면이 움직이고, Shift를 누르면 양쪽이 함께 움직입니다. 윤곽에서는 "
       "모서리를 끌고, 중점을 끌어 모서리를 추가하고, 모서리를 두 번 클릭해 지웁니다."),
    DE("Einen Griff ziehen, um diese Seite zu verschieben; mit Umschalt bewegen sich "
       "beide Seiten. Bei einem Umriss eine Ecke ziehen, einen Mittelpunkt ziehen, um "
       "eine hinzuzufügen, eine Ecke doppelklicken, um sie zu entfernen."),
    FR("Tirez une poignée pour déplacer ce côté ; avec Maj, les deux côtés bougent. Sur "
       "un contour, tirez un coin, tirez un milieu pour en ajouter un, double-cliquez un "
       "coin pour le retirer."),
    ES("Arrastra un tirador para mover ese lado; con Mayús se mueven ambos lados. En un "
       "contorno, arrastra una esquina, arrastra un punto medio para añadir una y haz "
       "doble clic en una esquina para quitarla."),
    PT("Arraste uma pega para mover esse lado; com Shift movem-se os dois lados. Num "
       "contorno, arraste um canto, arraste um ponto médio para acrescentar um e faça "
       "duplo clique num canto para o remover."),
    IT("Trascina una maniglia per spostare quel lato; con Maiusc si muovono entrambi i "
       "lati. Su un contorno, trascina un angolo, trascina un punto medio per "
       "aggiungerne uno, fai doppio clic su un angolo per toglierlo."),
    NL("Sleep een greep om die kant te verplaatsen; met Shift bewegen beide kanten. Bij "
       "een omtrek: sleep een hoek, sleep een middelpunt om er een toe te voegen, "
       "dubbelklik op een hoek om hem te verwijderen."),
    RU("Тащите маркер, чтобы сдвинуть эту сторону; с Shift двигаются обе стороны. У "
       "контура тащите угол, тащите середину стороны, чтобы добавить угол, двойной "
       "щелчок по углу удаляет его."),
    TR("O kenarı taşımak için bir tutamacı sürükleyin; Shift ile iki kenar birlikte "
       "taşınır. Bir ana hatta köşeyi sürükleyin, köşe eklemek için orta noktayı "
       "sürükleyin, silmek için köşeye çift tıklayın."));

SS_MSG(hint_rotate,
    EN("Drag a ring to turn the shape about that axis. Ctrl turns in 15-degree steps."),
    JA("リングをドラッグすると、その軸のまわりに図形が回ります。Ctrl で 15 度刻み。"),
    ZH_HANS("拖动圆环可绕该轴转动形状。按住 Ctrl 以 15 度为步长。"),
    ZH_HANT("拖動圓環可繞該軸轉動形狀。按住 Ctrl 以 15 度為步長。"),
    KO("고리를 끌면 그 축을 중심으로 도형이 돕니다. Ctrl을 누르면 15도씩 돕니다."),
    DE("Einen Ring ziehen, um die Form um diese Achse zu drehen. Strg dreht in "
       "15-Grad-Schritten."),
    FR("Tirez un anneau pour tourner la forme autour de cet axe. Ctrl tourne par pas "
       "de 15 degrés."),
    ES("Arrastra un anillo para girar la forma sobre ese eje. Ctrl gira en pasos de 15 "
       "grados."),
    PT("Arraste um anel para rodar a forma em torno desse eixo. Ctrl roda em passos de "
       "15 graus."),
    IT("Trascina un anello per ruotare la forma attorno a quell'asse. Ctrl ruota a "
       "passi di 15 gradi."),
    NL("Sleep een ring om de vorm om die as te draaien. Ctrl draait in stappen van 15 "
       "graden."),
    RU("Тащите кольцо, чтобы повернуть фигуру вокруг этой оси. Ctrl поворачивает "
       "шагами по 15 градусов."),
    TR("Şekli o eksen etrafında döndürmek için bir halkayı sürükleyin. Ctrl 15 "
       "derecelik adımlarla döndürür."));

SS_MSG(hint_draw,
    EN("Click the corners of the outline. Enter, a right click or the first corner "
       "closes it; Backspace takes the last one back; Esc cancels."),
    JA("輪郭の角をクリックします。Enter、右クリック、または最初の角で閉じます。"
       "Backspace で最後の角を取り消し、Esc で中止します。"),
    ZH_HANS("点击轮廓的各个角。按 Enter、右键或点击第一个角即可闭合；Backspace 撤回最"
            "后一个；Esc 取消。"),
    ZH_HANT("點擊輪廓的各個角。按 Enter、右鍵或點擊第一個角即可閉合；Backspace 撤回最"
            "後一個；Esc 取消。"),
    KO("윤곽의 모서리를 클릭합니다. Enter, 오른쪽 클릭 또는 첫 모서리로 닫고, "
       "Backspace로 마지막 모서리를 되돌리며, Esc로 취소합니다."),
    DE("Die Ecken des Umrisses anklicken. Eingabe, ein Rechtsklick oder die erste Ecke "
       "schließt ihn; Rücktaste nimmt die letzte zurück; Esc bricht ab."),
    FR("Cliquez les coins du contour. Entrée, un clic droit ou le premier coin le "
       "ferme ; Retour arrière annule le dernier ; Échap abandonne."),
    ES("Haz clic en las esquinas del contorno. Intro, un clic derecho o la primera "
       "esquina lo cierra; Retroceso deshace la última; Esc cancela."),
    PT("Clique nos cantos do contorno. Enter, um clique direito ou o primeiro canto "
       "fecha-o; Backspace desfaz o último; Esc cancela."),
    IT("Fai clic sugli angoli del contorno. Invio, un clic destro o il primo angolo lo "
       "chiude; Backspace toglie l'ultimo; Esc annulla."),
    NL("Klik op de hoeken van de omtrek. Enter, een rechterklik of de eerste hoek "
       "sluit hem; Backspace neemt de laatste terug; Esc annuleert."),
    RU("Щёлкайте углы контура. Enter, правый щелчок или первый угол замыкают его; "
       "Backspace убирает последний; Esc отменяет."),
    TR("Ana hattın köşelerine tıklayın. Enter, sağ tık ya da ilk köşe onu kapatır; "
       "Backspace sonuncuyu geri alır; Esc iptal eder."));

SS_MSG(show_outlines,
    EN("Show every shape's outline"), JA("すべての図形の枠を表示"),
    ZH_HANS("显示所有形状的线框"), ZH_HANT("顯示所有形狀的線框"),
    KO("모든 도형의 윤곽선 표시"), DE("Umrisse aller Formen zeigen"),
    FR("Afficher les contours de toutes les formes"),
    ES("Mostrar el contorno de todas las formas"), PT("Mostrar o contorno de todas as formas"),
    IT("Mostra il contorno di tutte le forme"), NL("De omtrek van elke vorm tonen"),
    RU("Показывать каркас каждой фигуры"), TR("Tüm şekillerin çerçevesini göster"));

SS_MSG(stats_points,
    EN("Points inside: {0} of {1} ({2}%)"), JA("内側の点: {1} 点中 {0} 点（{2}%）"),
    ZH_HANS("内部的点：{0} / {1}（{2}%）"), ZH_HANT("內部的點：{0} / {1}（{2}%）"),
    KO("안쪽 점: {1}개 중 {0}개 ({2}%)"), DE("Punkte innen: {0} von {1} ({2} %)"),
    FR("Points à l'intérieur : {0} sur {1} ({2} %)"), ES("Puntos dentro: {0} de {1} ({2} %)"),
    PT("Pontos dentro: {0} de {1} ({2}%)"), IT("Punti all'interno: {0} su {1} ({2}%)"),
    NL("Punten binnen: {0} van {1} ({2}%)"), RU("Точек внутри: {0} из {1} ({2}%)"),
    TR("İçerideki nokta: {1} içinden {0} (%{2})"));

SS_MSG(stats_cameras,
    EN("Cameras inside: {0} of {1}"), JA("内側のカメラ: {1} 台中 {0} 台"),
    ZH_HANS("内部的相机：{0} / {1}"), ZH_HANT("內部的相機：{0} / {1}"),
    KO("안쪽 카메라: {1}대 중 {0}대"), DE("Kameras innen: {0} von {1}"),
    FR("Caméras à l'intérieur : {0} sur {1}"), ES("Cámaras dentro: {0} de {1}"),
    PT("Câmaras dentro: {0} de {1}"), IT("Fotocamere all'interno: {0} su {1}"),
    NL("Camera's binnen: {0} van {1}"), RU("Камер внутри: {0} из {1}"),
    TR("İçerideki kamera: {1} içinden {0}"));

SS_MSG(stats_whole,
    EN("No shape is ticked, so nothing limits training yet."),
    JA("チェックされた図形がないため、まだ学習範囲は制限されていません。"),
    ZH_HANS("没有勾选任何形状，因此训练范围尚未受限。"),
    ZH_HANT("沒有勾選任何形狀，因此訓練範圍尚未受限。"),
    KO("체크한 도형이 없어서 아직 학습 범위가 제한되지 않습니다."),
    DE("Keine Form ist angehakt, also schränkt noch nichts das Training ein."),
    FR("Aucune forme n'est cochée : rien ne limite encore l'entraînement."),
    ES("No hay ninguna forma marcada, así que nada limita aún el entrenamiento."),
    PT("Nenhuma forma está marcada, por isso nada limita ainda o treino."),
    IT("Nessuna forma è spuntata, quindi niente limita ancora l'addestramento."),
    NL("Er is geen vorm aangevinkt, dus nog niets beperkt de training."),
    RU("Ни одна фигура не отмечена, поэтому обучение пока ничем не ограничено."),
    TR("İşaretli şekil yok, bu yüzden henüz eğitimi hiçbir şey sınırlamıyor."));

// ===========================================================================
// The training screen
// ===========================================================================

SS_MSG(train_label,
    EN("Region of interest"), JA("関心領域"), ZH_HANS("感兴趣区域"), ZH_HANT("感興趣區域"),
    KO("관심 영역"), DE("Interessenbereich"), FR("Région d'intérêt"),
    ES("Región de interés"), PT("Região de interesse"), IT("Regione di interesse"),
    NL("Interessegebied"), RU("Область интереса"), TR("İlgi bölgesi"));

SS_MSG(train_auto,
    EN("Automatic: {0}"), JA("自動: {0}"), ZH_HANS("自动：{0}"), ZH_HANT("自動：{0}"),
    KO("자동: {0}"), DE("Automatisch: {0}"), FR("Automatique : {0}"), ES("Automática: {0}"),
    PT("Automática: {0}"), IT("Automatica: {0}"), NL("Automatisch: {0}"),
    RU("Автоматически: {0}"), TR("Otomatik: {0}"));

SS_MSG(train_auto_none,
    EN("Automatic (none saved)"), JA("自動（保存なし）"), ZH_HANS("自动（未保存任何区域）"),
    ZH_HANT("自動（未儲存任何區域）"), KO("자동 (저장된 영역 없음)"),
    DE("Automatisch (keiner gespeichert)"), FR("Automatique (aucune enregistrée)"),
    ES("Automática (ninguna guardada)"), PT("Automática (nenhuma guardada)"),
    IT("Automatica (nessuna salvata)"), NL("Automatisch (geen opgeslagen)"),
    RU("Автоматически (нет сохранённых)"), TR("Otomatik (kayıtlı yok)"));

SS_MSG(train_none,
    EN("None: the whole scene"), JA("なし: シーン全体"), ZH_HANS("无：整个场景"),
    ZH_HANT("無：整個場景"), KO("없음: 장면 전체"), DE("Keiner: die ganze Szene"),
    FR("Aucune : toute la scène"), ES("Ninguna: toda la escena"),
    PT("Nenhuma: a cena inteira"), IT("Nessuna: l'intera scena"),
    NL("Geen: de hele scène"), RU("Нет: вся сцена"), TR("Yok: tüm sahne"));

SS_MSG(train_edit_region,
    EN("Edit Region"), JA("領域を編集"), ZH_HANS("编辑区域"), ZH_HANT("編輯區域"),
    KO("영역 편집"), DE("Bereich bearbeiten"), FR("Modifier la région"),
    ES("Editar la región"), PT("Editar a região"), IT("Modifica regione"),
    NL("Gebied bewerken"), RU("Изменить область"), TR("Bölgeyi Düzenle"));

SS_MSG(train_help,
    EN("The model grows only inside this region, and pixels that show only what lies "
       "outside it are left out of training. Automatic takes the first region saved "
       "for this dataset."),
    JA("モデルはこの領域の中でだけ成長し、領域外しか写っていない画素は学習から外され"
       "ます。「自動」はこのデータセットに最初に保存された領域を使います。"),
    ZH_HANS("模型只在该区域内增长，只拍到区域外内容的像素不参与训练。“自动”使用为本"
            "数据集保存的第一个区域。"),
    ZH_HANT("模型只在該區域內增長，只拍到區域外內容的像素不參與訓練。「自動」使用為本"
            "資料集儲存的第一個區域。"),
    KO("모델은 이 영역 안에서만 자라고, 영역 밖만 보이는 픽셀은 학습에서 빠집니다. "
       "자동은 이 데이터셋에 저장된 첫 번째 영역을 씁니다."),
    DE("Das Modell wächst nur innerhalb dieses Bereichs, und Pixel, die nur zeigen, "
       "was außerhalb liegt, bleiben beim Training außen vor. Automatisch nimmt den "
       "ersten für diesen Datensatz gespeicherten Bereich."),
    FR("Le modèle ne croît qu'à l'intérieur de cette région, et les pixels qui ne "
       "montrent que l'extérieur sont écartés de l'entraînement. Automatique prend la "
       "première région enregistrée pour ce jeu de données."),
    ES("El modelo solo crece dentro de esta región, y los píxeles que solo muestran lo "
       "que queda fuera se excluyen del entrenamiento. Automática toma la primera "
       "región guardada para este conjunto de datos."),
    PT("O modelo só cresce dentro desta região, e os píxeis que só mostram o que fica "
       "fora dela ficam fora do treino. Automática usa a primeira região guardada para "
       "este conjunto de dados."),
    IT("Il modello cresce solo dentro questa regione, e i pixel che mostrano solo ciò "
       "che sta fuori sono esclusi dall'addestramento. Automatica prende la prima "
       "regione salvata per questo dataset."),
    NL("Het model groeit alleen binnen dit gebied, en pixels die alleen tonen wat "
       "erbuiten ligt, doen niet mee met de training. Automatisch neemt het eerste "
       "gebied dat voor deze dataset is opgeslagen."),
    RU("Модель растёт только внутри этой области, а пиксели, на которых видно лишь то, "
       "что снаружи, исключаются из обучения. «Автоматически» берёт первую область, "
       "сохранённую для этого набора данных."),
    TR("Model yalnızca bu bölgenin içinde büyür; yalnızca dışarıdakini gösteren "
       "pikseller eğitimin dışında kalır. Otomatik, bu veri kümesi için kaydedilen ilk "
       "bölgeyi kullanır."));

}  // namespace roi
}  // namespace msg
}  // namespace i18n
}  // namespace spirula

#include "i18n/EndCatalog.h"
