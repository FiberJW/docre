
let makeToc = tocItems => {
  tocItems |> List.map(((level, name, id, cls)) => {
    Printf.sprintf({|<a href="#%s" class='level-%d %s'>%s</a>|}, id, level, cls, name)
  }) |> String.concat("\n");
};

let showPackage = projectListing => {
  "<div class='project-listing'><div class='project-title'>Package modules</div>" ++ {
    projectListing |> List.map(((htmlName, name)) => Printf.sprintf({|<a href="%s">%s</a>|}, htmlName, name)) |> String.concat("\n")
  } ++ "</div>"
};

let makeMarkdowns = markdowns => {
  if (markdowns == []) {
    ""
  } else {
    "<div class='docs-listing'>" ++ {
      markdowns |> List.map(((path, name)) => {
        Printf.sprintf({|<a href="%s">%s</a>|}, path, name)
      }) |> String.concat("\n")
    } ++ "</div>"
  }
};

let generate = (name, tocItems, projectListing, markdowns, searchPath) => {
  Printf.sprintf({|
    <div class='sidebar-wrapper'>
    <div class='sidebar-expander'>Show navigation</div>
    <div class='sidebar'>
      <a href="%s" style="display: block; padding: 0 8px;">Search</a>
      %s
      <div class='table-of-contents'>
      <div class='toc-header'>Page Contents</div>
      %s
      </div>
      %s
    </div>
    </div>
  |},
  searchPath,
  makeMarkdowns(markdowns),
  makeToc(tocItems),
  projectListing == [] ? "" : showPackage(projectListing)
  )
};
