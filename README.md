# FirstTestCode
GitHubを扱う最初のテストコード
## markdownについて
markdownというのは、いろんなところで使われているWiki記述的なフォーマットのことである。調べたらすぐわかります。
## 変更とコミットとプッシュについて
- 変更の履歴はテキストファイルの行番号ごとに行われる。
このため、行番号を持たないバイナリファイルの場合は
差分で保存されるのではなく、コピーがどんどん保存され
上限の100MBをすぐ超えてしまうので、除外しましょう。
-- 除外するには.gitignoreを編集します。
-- 例えばitch.ioなどでダウンロードしてきたアセットをGitHub管理下においてしまうとまずいことになります
+++ まずライセンスの問題。フリーでも製作者はitch.ioからダウンロードは許可してるけど
	あなたのサイトからのダウンロードは許可していません。
+++ zipや大量のpngがバージョン管理に含まれてしまうと、サイズを圧迫し、本来必要なデータ
	をアップロードすることができなくなります。
--- なのでチーム間で、素材を共有する場合はそのURLをテキストして保存し、どこからダウンロードすべきか、
	どのように使うべきか、どこに配置すべきかを記載したテキストをバージョン管理に含める。
	

# チームで使う場合…
とにかく、誰かのリポジトリに作る必要があるので、チームを
作った段階で、誰かリーダー/プロジェクト管理者を決めて
そいつのリポジトリで作業する。
## プロジェクト管理者(偉いわけじゃない)へ
- 自分がプロジェクト管理者でメンバーを追加するには
リポジトリの「Setting」をクリックし、
- ManageAccess→Collabolatorの招待(Invite a Collaborator)で
メンバーを追加します。当然Collabolatorはアカウントを
持っているものとします。
- Invite(招待)するとメールが届きますので、そのURLにジャンプ
その後AcceptInvitationすることで、チームのメンバーとして
閲覧、編集をすることができます。
- 学内でやる分には学校のRedmineを使うことになると思いますが、
もし学内サーバだと、学外の人がアクセスしづらいので
GitHubを使う選択肢をするなら、Inviteで追加していきましょう。
- また、オープンソースプロジェクトのコラボレータとして
名を売るのもありです。
-- 国内のオープンソースプロジェクトでコラボレータ募集してる
プロジェクト：Effekseer(swdがほぼ一人で作ってる)


てな感じです。
