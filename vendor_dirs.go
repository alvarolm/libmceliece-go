//go:build dummy

package mceliece

// "go mod vendor" only copies directories that are Go packages reachable in the
// import graph, but it resolves imports ignoring build constraints. These blank
// imports therefore make lib/ visible to vendoring without affecting any build.
import (
	_ "github.com/alvarolm/libmceliece-go/lib/amd64"
	_ "github.com/alvarolm/libmceliece-go/lib/arm64"
	_ "github.com/alvarolm/libmceliece-go/lib/include"
)
